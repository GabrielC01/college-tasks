! Program to invert an array and
! sum its even index elements.
! Couldn't use ubound function
program e2
    integer array(0:6)
    integer :: aux, j = size(array) - 1, sum = 0
    array = (/1, 2, 3, 4, 5, 6, 7/)

    do i = 0, (size(array)-1) / 2 - 1
      aux = array(i)
      array(i) = array(j)
      array(j) = aux
      j = j - 1
    end do

    do i = 0, size(array) - 1
      sum = sum + merge(array(i), 0, i .eq. 0 .or. mod(i, 2) .eq. 0)
    end do

    print*, 'Vetor invertido: ', array
    print *, 'Soma dos elementos de indice par: ', sum
end program e2
