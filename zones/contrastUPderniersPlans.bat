:: for %%d in (*) do echo %%d
for %%f in (%*) do D:\_PORTABLE_\moiSofts\media\imageMagick\convert.exe %%f -level 70%%,100%% %%f
pause
