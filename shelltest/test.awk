BEGIN{
        printf "%s\t%s\n","名字","攻击";
        sum=0;
    }
    #在遍历每一行的过程中输出每一行的内容，将库存加到sum变量
$3>10000{
        printf "%s\t%s\n",$1,$3;
        sum+=1;
    }
    #遍历完之后输出sum变量
 END{   
     printf "高攻击人数:%d\n",sum
 }
