reset	
# set term postscript eps enhanced color  
# set output "r1.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key left top# 凡例の位置
set size ratio 1
set grid 
set xlabel "time t (10^8 yr)"
set ylabel "scale facteor a"
set xrange [0.:300.] # x軸の範囲
set yrange [1.:4.] # y軸の範囲
set xtics 50 #x軸メモリの間隔
set ytics 0.5 #x軸メモリの間隔
plot "r1.txt" u 1:2 ti "Om = 0.3" dt 1 lc 6 lw 3 w l,\
    "r1.txt" u 1:3 ti "   = 0.8" dt 1 lc 1 lw 3 w l,\
    "r1.txt" u 1:4 ti "   = 1.1" dt 1 lc 4 lw 3 w l
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味