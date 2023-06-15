reset	
#set term postscript eps enhanced color  
#set output "02q1.eps" # xxx.epsファイルにグラフを出力
set size 0.5 # 拡大したい場合は小さくする
set key left bottom # 凡例の位置
set grid # グリッドの追加
set xlabel "x [rad]"
set ylabel "y"
set xrange [-pi/4.:pi/4.] # x軸の範囲
set yrange [-4.:4.] # y軸の範囲
plot "02q1.txt" u 1:2 ti "y = f(x) = tan(x)" dt 1 lc 1 lw 3 w l,\
     "02q1.txt" u 1:3 ti "f'(x) 4st order" dt 2 lc 2 lw 3 w l,\
     "02q1.txt" u 1:4 ti "f'''(x) 4st order" dt 3 lc 4 lw 3 w l
     
     
# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味