reset	
# set term postscript eps enhanced color  
# set output "09e1_x.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key left top # 凡例の位置
set grid 
set xlabel "t"
set ylabel "y"
set xrange [0.:1.] # x軸の範囲
#set yrange [0.:1.] # y軸の範囲
plot "09e1_E1.txt" u 1:3 ti "Euler 1st-order" dt 1 lc 4 lw 1 w l,\
     "09e1_RK4.txt" u 1:3 ti "Runge-Kutta 4th-order" dt 3 lc 3 lw 3 w l,\
     1./sqrt(2.)*sinh(sqrt(2.)*x) ti "true" lc 8
     
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味