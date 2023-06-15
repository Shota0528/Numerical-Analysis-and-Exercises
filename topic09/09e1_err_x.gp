reset	
# set term postscript eps enhanced color  
# set output "09e1_err_x.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key right bottom # 凡例の位置
set grid
set log y # y軸をlogにする
set format y "10^{%L}" # y軸を10の何乗とかと表示
set xlabel "t"
set ylabel "|(x - x_{tr}) / x_{tr}|"
set xrange [0.:1.] # x軸の範囲
set yrange [1e-12:] # y軸の範囲
plot "09e1_E1.txt" u 1:6 ti "Euler 1st-order" dt 1 lc 4 lw 2 w l,\
     "09e1_RK4.txt" u 1:6 ti "Runge-Kutta 4th-order" dt 3 lc 3 lw 3 w l
     
     
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味