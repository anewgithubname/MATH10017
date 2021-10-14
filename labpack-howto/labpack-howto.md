
# Table of Contents

1.  [Download the labpack](#orgfc940b1)
2.  [Extract the zip file using 7zip](#orgc0e3084)
3.  [Using the labpack](#org4c5f3b0)
4.  [Compiling &ldquo;Hello, world!&rdquo;](#orgf4bff3e)
5.  [Compiling from the terminal](#orgbce88a6)



<a id="orgfc940b1"></a>

# Download the labpack

Click [here](https://uob-my.sharepoint.com/personal/sl9885_bristol_ac_uk/_layouts/15/onedrive.aspx?id=%2Fpersonal%2Fsl9885%5Fbristol%5Fac%5Fuk%2FDocuments%2FTeaching%2FTeaching%5F2021%2D2022%2FLabPack%5FFull%2Ezip&parent=%2Fpersonal%2Fsl9885%5Fbristol%5Fac%5Fuk%2FDocuments%2FTeaching%2FTeaching%5F2021%2D2022&originalPath=aHR0cHM6Ly91b2ItbXkuc2hhcmVwb2ludC5jb20vOnU6L2cvcGVyc29uYWwvc2w5ODg1X2JyaXN0b2xfYWNfdWsvRVY2RHpGOFFPQ3RQaUlmczFOVk9HVWdCTjRiT1lRREVWdzNaMHVfUXlacEJRdz9ydGltZT1zQ1ZwYm5lTzJVZw) to find the labpack on sharepoint; you may have to enter your ID and password.

Click &ldquo;download the entire zip file&rdquo;.

![img](./cap5.png)

Save the file.

![img](./cap6.png)

Wait until the download is complete before trying to open it.
If it says &ldquo;Download Failed&rdquo;, click the circular arrow to restart the download.

Open the file in the file explorer:

![img](./cap8.png)


<a id="orgc0e3084"></a>

# Extract the zip file using 7zip

Right click on the labpack and unzip it using 7zip (choose &ldquo;Extract here&rdquo;):

![img](./cap10.png)

It will take about 5 minutes to unzip.


<a id="org4c5f3b0"></a>

# Using the labpack

Open the labpack:

![img](./cap12.png)

Double-click on the &ldquo;lab<sub>1</sub>&rdquo; .bat file to launch VSCode:

![img](./cap13.png)

(If it says you can&rsquo;t open it, click &ldquo;more info&rdquo;, then say &ldquo;open anyway&rdquo;.)

Accept the trust settings:

![img](./cap14.png)


<a id="orgf4bff3e"></a>

# Compiling &ldquo;Hello, world!&rdquo;

Double click on &ldquo;main.c&rdquo; to see the code for &ldquo;Hello, world!&rdquo;.

From the top menu, choose &ldquo;Start Debugging&rdquo; from the &ldquo;Run&rdquo; category:

![img](./cap16.png)

Choose &ldquo;C++ (GDB/LLDB)&rdquo;:

![img](./cap17.png)

Choose &ldquo;gcc&rdquo;:

![img](./cap18.png)

After a while, you should see a menu on the bottom half of VSCode.
Select &ldquo;TERMINAL&rdquo; to see the output of the program:

![img](./cap19.png)


<a id="orgbce88a6"></a>

# Compiling from the terminal

Type &ldquo;ls&rdquo; (letter l, not number 1) in the terminal and hit &ldquo;enter&rdquo;:

![img](./cap20.png)

This shows files in the current directory (folder): main.c is the hello world program we compiled, and main.exe is the program that the compiler output.

To compile from the command line, type `gcc main.c -o main.exe` in the terminal and hit enter.
To run the program, type `./main.exe`.

![img](./cap21.png)

