reset	
# set term postscript eps enhanced color  
# set output "08e1_err.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key right bottom # 凡例の位置
set grid
set log y # y軸をlogにする
set format y "10^{%L}" # y軸を10の何乗とかと表示
set xlabel "t"
set ylabel "|(y - y_{tr}) / y_{tr}|"
set xrange [0.:1.] # x軸の範囲
#set yrange [-4.:4.] # y軸の範囲
plot "08e1_E1.txt" u 1:4 ti "Euler 1st-order" dt 1 lc 4 lw 2 w l,\
     "08e1_RK2.txt" u 1:4 ti "Runge-Kutta 2nd-order" dt 2 lc 7 lw 2 w l,\
     "08e1_RK4.txt" u 1:4 ti "Runge-Kutta 4th-prder" dt 3 lc 3 lw 2 w l
     
     
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味