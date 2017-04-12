void piki (float* amplitudes, float* frequences, float* x, float* y, int* l) //x, y - АиЧ текущего трэка; l - число пиков текущего трэка
{int i, j, t, flag;
l=0;
for (i=0; i<=q; i++) //идем по значениям функции, где N - максимальное кол-во значений в массивах АЧХ
 if (amplitudes[i]>501)
 {
  t=501;
  while ((amplitudes[i]>501)&&(i<=q))	//рассматриваем пик
  {
   if (amplitudes[i]>t)	//ищем максимум пика
   {
    t=amplitudes[i];
    j=i;
   }
   i++;
  }
  x[l]=amplitudes[j];	//забиваем амплитуду пика
  y[l]=frequences[j];	//забиваем частоту пика
  l++;				//увеличиваем l, которая покажет, сколько у нас было пиков
 }
}



bool analysis (float* x, float* y, float* p, float* r, int n, int l)	//x, y - АиЧ текущего трэка; p, r - АиЧ трэка из базы
{																		//n - кол-во пиков трэка в базе, l - кол-во пиков текущего трэка
int i, flag;
float m, k;
if ((l-n<10)&&(n-l<10))		//если разность пиков меньше 10
{
 print("Количество пиков похоже ");
 k=x[1]/p[1];
 flag=0; i=2;
 while ((i<l)&&(i<n)&&(flag==0))
 {
  if ((p[i]*k-x[i]>800)||(x[i]-p[i]*k>800))	//если разница амплитуд больше 800
   flag=1;
  i++;
 }
 if (flag==1)
 {
  print("Амплитуды не схожи ");
  return 0;
 }
 else
 {
  flag=0;
  print("Амплитуды схожи ");
  m=y[1]/r[1]; i=2;
  while ((i<l)&&(i<n)&&(flag==0))
  {
   if ((r[i]*m-y[i]>8)||(y[i]-r[i]*m>8))		//если разница частот не больше 8
    flag=1;
   i++;}
  if (flag==1)
  {
   print("Частоты не схожи ");
   return 0;}
  else
  {
   print("Частоты схожи ");
   if ((l-n<3)&&(n-l<3)&&(k<1.05)&&(k>0.95)&&(m<1.05)&&(m>0.95))
   {
    print("Трэки одинаковые ");	//если коэффициенты ОЧЕНЬ близки
    return 1;
   }
   else
   {
    print("Трэки схожи ");
    return 1;
   }
  }
 }
}
else
{
 print ("Количество пиков разное ");
 print ("Трэки разные");
 return 0;
}
}
