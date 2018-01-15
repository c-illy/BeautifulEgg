:: for %%d in (*) do echo %%d
::dupliquer calque jusqu'à 8 copies (oui, fallait beaucoup assombrir)
::x2
for %%f in (%*) do D:\_PORTABLE_\moiSofts\media\imageMagick\composite.exe %%f %%f %%f

::x4
for %%f in (%*) do D:\_PORTABLE_\moiSofts\media\imageMagick\composite.exe %%f %%f %%f.png
::faudra supprimer à la main %%f.png

::4+6
for %%f in (%*) do D:\_PORTABLE_\moiSofts\media\imageMagick\composite.exe %%f %%f.png %%f
pause
