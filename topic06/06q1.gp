reset	
# set term postscript eps enhanced color  
# set output "06e2.eps" # xxx.epsファイルにグラフを出力
set size 0.8 # 拡大したい場合は小さくする
set key left bottom # 凡例の位置
set grid 
set xlabel "x"
set ylabel "y"
set xrange [-0.3:10.3] # x軸の範囲
#set yrange [0.:1.] # y軸の範囲
plot "06e2.txt" u 1:2 notitle  lc 8 lw 2 lt 6,\
     "06e2.txt" u ($1):($2):($3) with yerrorbar ti "Central values + 1{/Symbol s} errors" lt 1 lc 8 lw 2,\
     0.05*x*(x-4)*(x-9.19),\
     2.48*sin(0.71*x)

# dtで線の種類、lcで線の色、lwで線の太さを指定
# w l をつけると線になる。つけないとデータ点が表示される。
# u 1:2 は1列目をx軸、2列目をy軸にとると言う意味