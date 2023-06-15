reset	
# set term postscript eps enhanced color  
# set output "09q1.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key left bottom# 凡例の位置
set size ratio 1
set grid 
set xlabel "t"
set ylabel "theta"
set xrange [0.:10.] # x軸の範囲
set yrange [-1.:1.] # y軸の範囲
plot "09q1.txt" u 1:2 ti "t-theta" dt 1 lc 4 lw 3 w l,\
    pi/4 * sin(x)

# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味