#include <stdio.h>
#include <stdlib.h>

// 采用标准库，相比采用系统的open效率更高，因为内置优化，满足一定长度才会切换到系统代码执行，减少了系统代码和用户代码切换开销 
int main()
{
	int c = 0;
	FILE *pfin = NULL;
	FILE *pfout = NULL;
 
	//以只读方式打开数据文件
    pfin = fopen("Data.txt", "r");
    //以只写方式打开复制的新文件
	pfout = fopen("copy_stdio.out.txt", "w");
	
	while(fread(&c, sizeof(char), 1, pfin))//读数据
		fwrite(&c, sizeof(char), 1, pfout);//写数据
    //关闭文件流
	fclose(pfin);
	fclose(pfout);
	return 0;
}
