reset	
# set term postscript eps enhanced color  
# set output "13e1.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key left top # 凡例の位置
set grid 
set xlabel "x"
set ylabel "u(x,t)"
plot "13q1.txt" u 1:2 notitle dt 1 lw 1 w l


# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味