import math
import os

def clear_terminal():
    os.system("cls")

def prob_mobil(t, p):
    # mencari laju kejadian per menit
    lajuKejadian = -math.log(1-p)/t

    # mencari peluang melihat mobil dalam 10 menit
    waktu = 10 / 60 # konversi menit ke jam
    prob = 1 - math.exp(-lajuKejadian * waktu)
    return prob

def konversiPersen(prob_10):
    persen = prob_10 * 100
    return "{:.2f}%".format(persen)

clear_terminal()
# Meminta input dari user
p = float(input("Masukkan nilai peluang melihat mobil dalam 30 menit: "))
t = float(input("Masukkan waktu dalam satuan menit: "))

prob_10 = prob_mobil(t, p)
persentase_10 = konversiPersen(prob_10)

print("\n")
print("Peluang melihat mobil di jalan raya dalam 10 menit adalah : ", prob_10)
print("Persentase melihat mobil di jalan raya dalam 10 menit adalah : ", persentase_10)
