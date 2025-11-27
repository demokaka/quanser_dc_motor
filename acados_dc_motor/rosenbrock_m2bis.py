from acados_template import AcadosOcpSolver
import numpy as np
import casadi as ca

import time
from matplotlib import pyplot as plt

json_file = "acados_ocp_generic_nlp.json"
ocp_solver = AcadosOcpSolver(None, build=False, generate=False, json_file=json_file)

# warmup solver
ocp_solver.set(0, "x", np.array([0.0, 0.0]))
for k in range(5):
    r_example = 1.0 + 0.1 * k
    ocp_solver.set(0, "p", np.array([r_example]))
    status = ocp_solver.solve()

    if status != 0:
        print(f"warmup {k}, solver failed with returned status {status}")

r_values = np.linspace(0.0, 3.0, 101)

solving_time_ext = []
solving_time_int = []

xy_sol = []
cost_sol = []

t_init = time.time()
for r_value in r_values:
    ocp_solver.set(0, "p", np.array([r_value]))

    # solve
    start_time = time.time()
    status = ocp_solver.solve()
    solving_time = time.time() - start_time
    solving_time_ext.append(solving_time)

    x0 = ocp_solver.get(0, "x")
    xy_sol.append(x0)
    f_val = ocp_solver.get_cost()
    cost_sol.append(f_val)

    # print(f"r = {r_value:.2f}, x = {x0}, f = {f_val:.4f}, solve time = {solving_time*1e3:.2f} ms, status = {status}")

    t_int = ocp_solver.get_stats("time_tot")
    solving_time_int.append(t_int)

# total time
total_time = time.time() - t_init
print(f"Total time for {len(r_values)} solves: {total_time:.2f} s")

xy_sol = np.array(xy_sol)
cost_sol = np.array(cost_sol)
solving_time_ext = np.array(solving_time_ext)
solving_time_int = np.array(solving_time_int)

# plot results
plt.figure()
plt.subplot(3,1,1)
plt.plot(r_values, xy_sol[:,0], label='x1')
plt.plot(r_values, xy_sol[:,1], label='x2')
plt.xlabel('r')
plt.ylabel('Optimal x,y')

plt.subplot(3,1,2)
plt.plot(r_values, cost_sol)
plt.xlabel('r')
plt.ylabel('Optimal cost')

plt.subplot(3,1,3)
plt.plot(r_values, solving_time_ext*1e3, label='External time')
plt.plot(r_values, solving_time_int*1e3, label='Internal time')
plt.xlabel('r')
plt.ylabel('Solving time [ms]')
plt.legend()
plt.tight_layout()
plt.show()


