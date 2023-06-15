reset	
#set term postscript eps enhanced color  
#set output "08e2.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key right bottom# 凡例の位置
set grid 
set xlabel "t"
set ylabel "v"
set xrange [0.:7.] # x軸の範囲
#set yrange [0.:1.] # y軸の範囲
plot "08e2.txt" u 1:2 ti "t-v" dt 1 lc 4 lw 3 w l,\
    "08e2.txt" u 1:3 ti "g/c * (1 - e^(-ct))" dt 1 lc 3 lw 3  w l
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味