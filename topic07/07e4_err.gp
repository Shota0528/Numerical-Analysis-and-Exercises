reset	
# set term postscript eps enhanced color  
# set output "07e4.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key left bottom # 凡例の位置
set grid
set log y # y軸をlogにする
set format y "10^{%L}" # y軸を10の何乗とかと表示
set xlabel "a"
set ylabel "|(f - f_{tr}) / f_{tr}|"
set xrange [1.:3.] # x軸の範囲
set yrange [1e-15:] # y軸の範囲
plot "07e4.txt" u 1:4 notitle dt 1 lc 1 lw 3 w l
     
     
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味