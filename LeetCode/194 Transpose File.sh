

#!/binbash


# Memory Limit Exceeded

n=$(head -1 file.txt | wc -w)

for i in $( seq 1 $n );
do
  cat file.txt | awk -v i=$i '{print $i}' | tr '\n' '\ ' | sed 's/ $/\n/g'
done


awk '
{
    for (i = 1; i <= NF; i++) {
        if(NR == 1) {
            s[i] = $i;
        } else {
            s[i] = s[i] " " $i;
        }
    }
}
END {
    for (i = 1; s[i] != ""; i++) {
        print s[i];
    }
}' file.txt