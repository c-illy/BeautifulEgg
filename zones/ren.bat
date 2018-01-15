cd /d %~dp0


:: for %%d in (*) do echo %%d
::for %%f in (%*) do D:\_PORTABLE_\moiSofts\media\imageMagick\convert.exe %%f -level 70%%,100%% %%f

::for %%f in (%*) do SET "s=%%f" && call echo %%s:\=_%%
::for %%f in (%*) do SET "s=%%f" && call set "ss=%%s:\=_%%" && call echo %%ss%%
::for %%f in (%*) do SET "s=%%f" && call set "ss=%%s:\=_%%" && call echo %%ss:H:_Creajeu_OE_BeautifulEgg_zones_=%%
for %%f in (%*) do SET "s=%%f" && call set "ss=%%s:\=_%%" && call copy %%f %%ss:H:_Creajeu_OE_BeautifulEgg_zones_=%%

::H:_Creajeu_OE_BeautifulEgg_zones_

::SET "s=123456"
::echo %s% && echo %s:3=E%

pause

