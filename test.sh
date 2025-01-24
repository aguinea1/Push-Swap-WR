#!/bin/bash
if [ "$#" -ne 2 ]; then
    echo "Uso: sh $0 <rango> <movimientos>"
    exit 1
fi
RANGO=$1
UMBRAL=$2
SUMA=0
INTENTOS=0
while true; do
    rm -f test.txt checker.txt
    ARG=$(shuf -i 1-$RANGO -n $RANGO | tr '\n' ' ')
    ./push_swap $ARG > test.txt
    ./push_swap $ARG | ./checker $ARG > checker.txt
    VAR=$(wc -l < test.txt)
    SUMA=$((SUMA + VAR))
    INTENTOS=$((INTENTOS + 1))
    PROMEDIO=$((SUMA / INTENTOS))
    ULTIMA_LINEA=$(tail -n 1 checker.txt)
    if [ "$VAR" -lt "$UMBRAL" ] && [ "$ULTIMA_LINEA" = "OK" ]; then
        echo "\033[42m [OK] $VAR (Promedio: $PROMEDIO)\033[0m"  # Fondo verde
    else
        echo "\033[41m [KO] $VAR (Promedio: $PROMEDIO)\033[0m $ARG"  # Fondo rojo
        break
    fi
done
