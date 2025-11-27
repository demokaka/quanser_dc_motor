
from acados_template import AcadosOcp, AcadosOcpSolver, AcadosModel, ACADOS_INFTY
import numpy as np
import casadi as ca


def main():
    x = ca.SX.sym('x',2)
    r = ca.SX.sym('r',1)

    f = (1-x[0])**2 + (x[1]-x[0]**2)**2
    g = x[0]**2 + x[1]**2 -r

    glb = 0.0
    gub = 0.0

    # write a model
    model = AcadosModel()
    model.name = "generic_nlp"
    model.x = x
    model.p = r

    # acados ocp formulation
    ocp = AcadosOcp()
    ocp.name = "nlp_solver"
    ocp.model = model

    # terminal cost
    ocp.cost.cost_type_e = "EXTERNAL"
    ocp.model.cost_expr_ext_cost_e = f

    # terminal constraint
    ocp.model.con_h_expr_e = g
    ocp.constraints.lh_e = -ACADOS_INFTY
    ocp.constraints.uh_e = gub
    
    # initial parameters
    ocp.parameter_values = np.zeros((model.p.size()[0],))

    # solver options
    ocp.solver_options.N_horizon = 0
    ocp.solver_options.nlp_solver_type = "SQP"
    ocp.solver_options.qp_solver = "PARTIAL_CONDENSING_HPIPM"
    ocp.solver_options.hessian_approx = "GAUSS_NEWTON"
    
    ocp.code_export_directory = "c_generated_code_generic_nlp"
    ocp.json_file = "acados_ocp_generic_nlp.json"
    
    # create the solver
    ocp_solver = AcadosOcpSolver(ocp)

if __name__=="__main__":
    main()