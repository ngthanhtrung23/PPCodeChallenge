g++-4.9 -std=c++11 sol1.cpp -o sol1
for i in {0..19}
do
  echo "i = $i"
  ./sol1 < "$i.in" > "$i.out"
done
rm sol1
