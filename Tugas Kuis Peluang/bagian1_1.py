import os

def clear_terminal():
    os.system("cls")

# fungsi probabilitas andi tidak terlambat tidak hujan lalin padat
def p_a_t_tl_th_llp(p_h, p_ll_p_h, p_t_h_ll_p, p_t_th_ll_tp, p_t_sl):
    prob_t_tl = 1 - p_t_th_ll_tp - p_t_sl - (p_h * p_ll_p_h * p_t_h_ll_p)
    return prob_t_tl

# fungsi probabilitas andi akan datang terlambat
def p_terlambat(p_h, p_ll_p_h, p_t_h_ll_p, p_h_th, p_ll_tp_th, p_t_th_ll_tp, p_ll_tp_h, p_t_sl, p_ll_p_th):
    prob_terlambat = (p_h * p_ll_p_h * p_t_h_ll_p) + (p_h_th * p_ll_tp_th * p_t_th_ll_tp) + (p_h * p_ll_tp_h * p_t_sl) + (p_h_th * p_ll_p_th * p_t_sl)
    return prob_terlambat

# fungsi probabilitas andi tidak terlambat
def p_tidak_terlambat(p_terlambat):
    prob_tidak_terlambat = 1 - p_terlambat
    return prob_tidak_terlambat

# fungsi diketahui Andi datang terlambat, tentukan probabilitas pada waktu itu hari hujan
def p_bersyarat(p_t_h_ll_p, p_t_th_ll_tp, p_t_sl, p_h, p_h_th):
    prob_andi_datang_terlambat = p_t_h_ll_p * p_h + p_t_th_ll_tp * p_h_th + p_t_sl * (1 - p_h - p_h_th)
    prob_bersyarat = p_t_h_ll_p * p_h / prob_andi_datang_terlambat
    return prob_bersyarat

# ================================================================================================================================================== #

clear_terminal()
print("=== Mohon input dalam bentuk pecahan (contoh 1/4) ===\n")

# meminta input a dari user
a = input("Masukkan nilai probabilitas hujan turun pada suatu hari: ")
pembilang_a, penyebut_a = a.split("/") # memisahkan antara pembilang dan penyebut
p_h = int(pembilang_a) / int(penyebut_a) # mengubah ke dalam bilangan desimal

# meminta input b dari user
b = input("Masukkan nilai probabilitas lalin padat jika hujan turun: ")
pembilang_b, penyebut_b = b.split("/") 
p_ll_p_h = int(pembilang_b) / int(penyebut_b)

# meminta input c dari user
c = input("Masukkan nilai probabilitas lalin padat jika tidak hujan: ")
pembilang_c, penyebut_c = c.split("/")
p_ll_p_th = int(pembilang_c) / int(penyebut_c)

# meminta input d dari user
d = input("Masukkan nilai probabilitas Andi terlambat jika hujan dan lalin padat: ")
pembilang_d, penyebut_d = d.split("/")
p_t_h_ll_p = int(pembilang_d) / int(penyebut_d)

# meminta input e dari user
e = input("Masukkan nilai probabilitas Andi terlambat jika tidak hujan dan lalin tidak padat: ")
pembilang_e, penyebut_e = e.split("/")
p_t_th_ll_tp = int(pembilang_e) / int(penyebut_e)

# meminta input f dari user
f = input("Masukkan nilai probabilitas Andi terlambat pada situasi lain: ")
pembilang_f, penyebut_f = f.split("/")
p_t_sl = int(pembilang_f) / int(penyebut_f)

# probabilitas hujan tidak turun dalam sehari
p_h_th = 1 - p_h

# probabilitas lalin tidak padat jika hujan
p_ll_tp_h = 1 - p_ll_p_h

# probabilitas lalin tidak padat jika tidak hujan
p_ll_tp_th = 1 - p_ll_p_th

# probabilitas andi tidak terlambat jika hujan dan lalin tidak padat
p_tt_h_ll_tp = 1 - p_t_h_ll_p

# probabilitas andi tidak terlambat jika tidak hujan dan lalin padat
p_tt_th_llp = 1 - p_t_th_ll_tp

# Probabilitas Andi tidak terlambat jika hujan dan lalu lintas tidak padat, atau tidak hujan dan lalu lintas padat
p_tt_sl = 1 - p_t_sl


# tampilkan seluruh hasil input
print("\n=== Hasil inputan user ===\n")
print("Probabilitas hujan turun pada suatu hari: ", p_h)
print("Probabilitas lalin padat jika hujan turun: ", p_ll_p_h)
print("Probabilitas lalin padat jika tidak hujan: ", p_ll_p_th)
print("Probabilitas Andi terlambat jika hujan dan lalin padat: ", p_t_h_ll_p)
print("Probabilitas Andi terlambat jika tidak hujan dan lalin tidak padat: ", p_t_th_ll_tp)
print("Probabilitas Andi terlambat pada situasi lain: ", p_t_sl)

# Definisi soal dengan fungsi
jawabSoalno1 = p_a_t_tl_th_llp(p_h, p_ll_p_h, p_t_h_ll_p, p_t_th_ll_tp, p_t_sl)
jawabSoalno2 = p_terlambat(p_h, p_ll_p_h, p_t_h_ll_p, p_h_th, p_ll_tp_th, p_t_th_ll_tp, p_ll_tp_h, p_t_sl, p_ll_p_th)
jawabSoalno3 = p_bersyarat(p_t_h_ll_p, p_t_th_ll_tp, p_t_sl, p_h, p_h_th)

# Jawab soal no A
print("\n=== Jawab ===\n") 
print("[A] Probabilitas Andi tidak terlambat pada kondisi hari tidak hujan dan lalu lintas padat adalah: ", jawabSoalno1)
print("[B] Probabilitas Andi akan datang terlambat adalah: ", jawabSoalno2) 
print("[C] Probabilitas hari hujan jika diketahui andi datang terlambat adalah: ", jawabSoalno3)
