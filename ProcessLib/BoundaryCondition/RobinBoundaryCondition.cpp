/**
 * \copyright
 * Copyright (c) 2012-2016, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#include "RobinBoundaryCondition.h"
#include "ProcessLib/Utils/ProcessUtils.h"

namespace ProcessLib
{
std::unique_ptr<RobinBoundaryCondition> createRobinBoundaryCondition(
    BaseLib::ConfigTree const& config,
    std::vector<MeshLib::Element*>&& elements,
    NumLib::LocalToGlobalIndexMap const& dof_table, int const variable_id,
    int const component_id, unsigned const integration_order,
    unsigned const global_dim,
    std::vector<std::unique_ptr<ParameterBase>> const& parameters)
{
    DBUG("Constructing RobinBcConfig from config.");
    //! \ogs_file_param{boundary_condition__type}
    config.checkConfigParameter("type", "Robin");

    //! \ogs_file_param{boundary_condition__Robin__alpha}
    auto const alpha_name = config.getConfigParameter<std::string>("alpha");
    //! \ogs_file_param{boundary_condition__Robin__u_0}
    auto const u_0_name = config.getConfigParameter<std::string>("u_0");

    auto const& alpha = findParameter<double>(alpha_name, parameters, 1);
    auto const& u_0 = findParameter<double>(u_0_name, parameters, 1);

    return std::unique_ptr<RobinBoundaryCondition>(
        new RobinBoundaryCondition(
            integration_order, dof_table, variable_id, component_id, global_dim,
            std::move(elements),
            RobinBoundaryConditionData{alpha, u_0}));
}

}  // ProcessLib
