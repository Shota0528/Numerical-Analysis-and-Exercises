reset	
# set term postscript eps enhanced color  
# set output "09e1.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key left top# 凡例の位置
set size ratio 1
set grid 
set xlabel "t"
set ylabel "x or y"
set xrange [0.:1.] # x軸の範囲
set yrange [0.:11.] # y軸の範囲
plot "09e1.txt" u 1:2 ti "t-x" dt 1 lc 4 lw 3 w l,\
    "09e1.txt" u 1:3 ti "t-xtr" dt 1 lc 3 lw 3 w l,\
    "09e1.txt" u 1:4 ti "t-y" dt 1 lc 2 lw 3 w l,\
    "09e1.txt" u 1:5 ti "t-ytr" dt 1 lc 1 lw 3 w l
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味