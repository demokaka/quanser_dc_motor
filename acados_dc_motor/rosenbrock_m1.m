
%% clear everything
clc
clear all
close all

%% parametric

opti = casadi.Opti();

x = opti.variable();
y = opti.variable();
r = opti.parameter();

f = (1-x)^2+(y-x^2)^2;
opti.minimize(f);
con = x^2+y^2<=r;
opti.subject_to(con);

opti.solver('ipopt');

solving_time = [];
xy_sol = [];
timer = tic;
for r_value=linspace(1,3,25)
    opti.set_value(r,r_value)
    timer_sol = tic;
    sol = opti.solve();
    sol_t = toc(timer_sol);
    solving_time = [solving_time, sol_t*1e3];
    xy_sol = [xy_sol, [sol.value(x);sol.value(y)]]

end
total_time = toc(timer);    
