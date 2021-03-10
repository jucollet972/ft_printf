# ft_printf<br>

## ft_printf est une librairie dynamique reprenant la libft faite au préalable mais comportant la réplique d'une fonction bien connue de la librairie stdio: printf <br>

```c
int ft_printf(const char *format, ...);
```

* Conversions : ``c`` ``s`` ``p`` ``d`` ``i`` ``o`` ``O`` ``u`` ``x`` ``X`` ``%``
* Conversions Flags : ``l`` ``ll`` ``h`` ``hh``
* Formats Flags : ``space`` ``#`` ``+`` ``0`` ``-``
* Precision ``.``
* Taille minimum de champ
