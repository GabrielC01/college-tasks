clear all; clc; close all;
m = 6;
n = 5;

for i = 1:m
    for j = 1:n
        A(i,j) = i-2*j;
        B(i,j) = 7*j-5*i;
    end
end

At = A'
Bt = B'

% a) 2A + 3B
a = 2*A + 3*B

% b)A^t - B^t
b = At - Bt

% c) A^2 - B
c = A.^2 - B

% d) A · B - B · A
d = A*B - B*A % Error