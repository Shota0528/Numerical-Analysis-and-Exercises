reset	
#set term postscript eps enhanced color  
#set output "02e3.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key left bottom # 凡例の位置
set grid # グリッドの追加
set xlabel "x [rad]"
set ylabel "y"
set xrange [0.:2.*pi] # x軸の範囲
set yrange [-1.:1.] # y軸の範囲
plot "02e3.txt" u 1:2 ti "y = f(x) = sin(x)" dt 1 lc 1 lw 3 w l,\
     "02e3.txt" u 1:3 ti "f'(x) 4st order" dt 2 lc 2 lw 3 w l,\
     "02e3.txt" u 1:4 ti "f'''(x) 4st order" dt 3 lc 7 lw 3 w l,\
     "02e3.txt" u 1:5 ti "f''''(x) 2nd order" dt 4 lc 4 lw 2 w l,\
     "02e3.txt" u 1:6 ti "f'''''(x) 2nd order" dt 5 lc 3 lw 2 w l
     
     
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味