void piki (float* amplitudes, float* frequences, float* x, float* y, int* l) //x, y - ��� �������� �����; l - ����� ����� �������� �����
{int i, j, t, flag;
l=0;
for (i=0; i<=q; i++) //���� �� ��������� �������, ��� N - ������������ ���-�� �������� � �������� ���
 if (amplitudes[i]>501)
 {
  t=501;
  while ((amplitudes[i]>501)&&(i<=q))	//������������� ���
  {
   if (amplitudes[i]>t)	//���� �������� ����
   {
    t=amplitudes[i];
    j=i;
   }
   i++;
  }
  x[l]=amplitudes[j];	//�������� ��������� ����
  y[l]=frequences[j];	//�������� ������� ����
  l++;				//����������� l, ������� �������, ������� � ��� ���� �����
 }
}



bool analysis (float* x, float* y, float* p, float* r, int n, int l)	//x, y - ��� �������� �����; p, r - ��� ����� �� ����
{																		//n - ���-�� ����� ����� � ����, l - ���-�� ����� �������� �����
int i, flag;
float m, k;
if ((l-n<10)&&(n-l<10))		//���� �������� ����� ������ 10
{
 print("���������� ����� ������ ");
 k=x[1]/p[1];
 flag=0; i=2;
 while ((i<l)&&(i<n)&&(flag==0))
 {
  if ((p[i]*k-x[i]>800)||(x[i]-p[i]*k>800))	//���� ������� �������� ������ 800
   flag=1;
  i++;
 }
 if (flag==1)
 {
  print("��������� �� ����� ");
  return 0;
 }
 else
 {
  flag=0;
  print("��������� ����� ");
  m=y[1]/r[1]; i=2;
  while ((i<l)&&(i<n)&&(flag==0))
  {
   if ((r[i]*m-y[i]>8)||(y[i]-r[i]*m>8))		//���� ������� ������ �� ������ 8
    flag=1;
   i++;}
  if (flag==1)
  {
   print("������� �� ����� ");
   return 0;}
  else
  {
   print("������� ����� ");
   if ((l-n<3)&&(n-l<3)&&(k<1.05)&&(k>0.95)&&(m<1.05)&&(m>0.95))
   {
    print("����� ���������� ");	//���� ������������ ����� ������
    return 1;
   }
   else
   {
    print("����� ����� ");
    return 1;
   }
  }
 }
}
else
{
 print ("���������� ����� ������ ");
 print ("����� ������");
 return 0;
}
}
