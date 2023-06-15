reset	
# set term postscript eps enhanced color  
# set output "07e4.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key left top # 凡例の位置
set grid 
set xlabel "a"
set ylabel "exp(-x*x/2)/sqrt(2*pi)"
set xrange [-3.:3.] # x軸の範囲
#set yrange [0.:1.] # y軸の範囲
plot "07q1.txt" u 1:2 ti "a-f" dt 1 lc 4 lw 3 w l,\
     exp(-x*x/2)/sqrt(2*pi)
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味