:: for %%d in (*) do echo %%d
for %%f in (%*) do D:\_PORTABLE_\moiSofts\media\imageMagick\montage.exe %%f -tile x1 -geometry +0+0 -alpha On -background "rgba(0, 0, 0, 0.0)" -quality 100 %%f.png
:: D:\_PORTABLE_\moiSofts\media\imageMagick\montage.exe %1 -tile x1 -geometry +0+0 -alpha On -background "rgba(0, 0, 0, 0.0)" -quality 100 %1.png
pause
