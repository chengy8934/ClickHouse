#pragma once
#include <Core/Block.h>

namespace DB
{

class QueryPipeline;
using QueryPipelinePtr = std::unique_ptr<QueryPipeline>;
using QueryPipelines = std::vector<QueryPipelinePtr>;

/// Description of data stream.
/// Single logical data stream may relate to many ports of pipeline.
class DataStream
{
public:
    Block header;

    /// Tuples with those columns are distinct.
    /// It doesn't mean that columns are distinct separately.
    /// Removing any column from this list brakes this invariant.
    NameSet distinct_columns = {};

    /// QueryPipeline has single port. Totals or extremes ports are not counted.
    bool has_single_port = false;

    /// Things which may be added:
    /// * sort description
    /// * limit
    /// * estimated rows number
    /// * memory allocation context
};

using DataStreams = std::vector<DataStream>;

/// Single step of query plan.
class IQueryPlanStep
{
public:
    virtual ~IQueryPlanStep() = default;

    virtual String getName() const = 0;

    /// Add processors from current step to QueryPipeline.
    /// Calling this method, we assume and don't check that:
    ///   * pipelines.size() == getInputStreams.size()
    ///   * header from each pipeline is the same as header from corresponding input_streams
    /// Result pipeline must contain any number of streams with compatible output header is hasOutputStream(),
    ///   or pipeline should be completed otherwise.
    virtual QueryPipelinePtr updatePipeline(QueryPipelines pipelines) = 0;

    const DataStreams & getInputStreams() const { return input_streams; }

    bool hasOutputStream() const { return output_stream.has_value(); }
    const DataStream & getOutputStream() const;

    /// Methods to describe what this step is needed for.
    const std::string & getStepDescription() const { return step_description; }
    void setStepDescription(std::string description) { step_description = std::move(description); }

protected:
    DataStreams input_streams;
    std::optional<DataStream> output_stream;

    /// Text description about what current step does.
    std::string step_description;
};

using QueryPlanStepPtr = std::unique_ptr<IQueryPlanStep>;
}
