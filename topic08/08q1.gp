reset	
# set term postscript eps enhanced color  
# set output "08q1.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key right bottom# 凡例の位置
set size ratio 1
set grid 
set xlabel "t"
set ylabel "y"
set xrange [0.:1.] # x軸の範囲
set yrange [0.:11.] # y軸の範囲
plot "08q1.txt" u 1:2 ti "t-y" dt 1 lc 4 lw 3 w l
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味