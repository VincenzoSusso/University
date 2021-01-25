S = 286797;
n = 5;
tolleranza = 1e-10;
max_iterate = 100;

[approssimazione, iterate] = calcolaRadiceN(S, n, tolleranza, max_iterate);

fprintf("Approssimazione radice %d in base %d: %.10f\n", S, n, approssimazione);
fprintf("Iterate: %d\n", iterate);
disp("Premi un tasto per continuare")
pause

clc
clear