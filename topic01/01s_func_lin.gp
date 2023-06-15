reset	
#set term postscript eps enhanced color  
#set output "01s_func_lin.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key left bottom # 凡例の位置
set xlabel "x"
set ylabel "y"
set xrange [-1.:2.] # x軸の範囲
# set yrange [-1:3] # y軸の範囲
plot "01s_func.txt" u 1:2 ti "y = f(x)" dt 1 lc 1 lw 2 w l
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味

#で始まる行はコメント行