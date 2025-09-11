# Math use in Padding

so I don't have to recalculate it over and over again if I need it.

> [!WARNING] 
> Assumes $n$ and $m$ are integers and $m > 0$.
>
> Also the modulo operator `%` (symbol might be different in other programming language) for other languages might behave differently in how they treat negative values.

## Chunk/Block Padding

from a number ($n$), get the next number ($n^+$) that is divisible by $m$.
 
$n^+ = n + m - (n \bmod m)$

amount to add to get the next multiple

$m - (n \bmod m)$

when talking about arrays, $n$ is the current size of the array, $m - (n \bmod m)$ is the total elements to add, and $n^+$ is the new size of the padded array.
