; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

<<<<<<< HEAD
@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@init_str = private unnamed_addr constant [42 x i8] c"uma rua deserta banhada por uma luz fraca\00", align 1
@fmt = private unnamed_addr constant [19 x i8] c"Cenario atual: %s\0A\00", align 1
@add_str = private unnamed_addr constant [23 x i8] c"No fim da rua um vulto\00", align 1
@fmt.1 = private unnamed_addr constant [19 x i8] c"Cenario atual: %s\0A\00", align 1
@alvo_str = private unnamed_addr constant [10 x i8] c"luz fraca\00", align 1
@subst_str = private unnamed_addr constant [21 x i8] c"escuridao que sufoca\00", align 1
@fmt.2 = private unnamed_addr constant [19 x i8] c"Cenario atual: %s\0A\00", align 1
@add_str.3 = private unnamed_addr constant [29 x i8] c"o cheiro de chuva e tragedia\00", align 1
@fmt.4 = private unnamed_addr constant [19 x i8] c"Cenario atual: %s\0A\00", align 1
@alvo_str.5 = private unnamed_addr constant [6 x i8] c"vulto\00", align 1
@subst_str.6 = private unnamed_addr constant [22 x i8] c"homem de terno branco\00", align 1
@fmt.7 = private unnamed_addr constant [19 x i8] c"Cenario atual: %s\0A\00", align 1

define i32 @main() {
entrada:
  %Alaide = alloca ptr, align 8
  %nova_pilha_ptr = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr, i32 0)
  store ptr %nova_pilha_ptr, ptr %Alaide, align 8
  %Loira = alloca ptr, align 8
  %nova_pilha_ptr1 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr1, i32 0)
  store ptr %nova_pilha_ptr1, ptr %Loira, align 8
  %Joao = alloca ptr, align 8
  %nova_pilha_ptr2 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr2, i32 0)
  store ptr %nova_pilha_ptr2, ptr %Joao, align 8
  %Abismo = alloca ptr, align 8
  %nova_pilha_ptr3 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr3, i32 0)
  store ptr %nova_pilha_ptr3, ptr %Abismo, align 8
  %"Esta chovendo" = alloca i1, align 1
  store i1 false, ptr %"Esta chovendo", align 1
  %"Esta chovendo4" = alloca i1, align 1
  store i1 true, ptr %"Esta chovendo4", align 1
  %Lembranca = alloca ptr, align 8
  store ptr @empty_str, ptr %Lembranca, align 8
  %nova_str_ptr = call ptr @string_criar(ptr @init_str)
  store ptr %nova_str_ptr, ptr %Lembranca, align 8
  %pilha_ptr = load ptr, ptr %Abismo, align 8
  call void @pilha_set_topo(ptr %pilha_ptr, i32 5)
  br label %while_cond

while_cond:                                       ; preds = %if_merge36, %entrada
  %load_bool_tmp = load i1, ptr %"Esta chovendo4", align 1
  br i1 %load_bool_tmp, label %while_body, label %while_merge

while_body:                                       ; preds = %while_cond
  %tmpstr = load ptr, ptr %Lembranca, align 8
  %0 = call i32 (ptr, ...) @printf(ptr @fmt, ptr %tmpstr)
  %pilha_ptr5 = load ptr, ptr %Loira, align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr5)
  %tmp_sum = add i32 %peeked_val, 1
  call void @pilha_set_topo(ptr %pilha_ptr5, i32 %tmp_sum)
  %pilha_ptr_var = load ptr, ptr %Loira, align 8
  %peeked_val6 = call i32 @pilha_peek(ptr %pilha_ptr_var)
  %cmpeq = icmp eq i32 %peeked_val6, 1
  br i1 %cmpeq, label %if_then, label %if_merge

while_merge:                                      ; preds = %while_cond
  ret i32 0

if_then:                                          ; preds = %while_body
  %load_str = load ptr, ptr %Lembranca, align 8
  %str_concatenada_ptr = call ptr @string_concatenar(ptr %load_str, ptr @add_str)
  store ptr %str_concatenada_ptr, ptr %Lembranca, align 8
  %tmpstr7 = load ptr, ptr %Lembranca, align 8
  %1 = call i32 (ptr, ...) @printf(ptr @fmt.1, ptr %tmpstr7)
  br label %if_merge

if_merge:                                         ; preds = %if_then, %while_body
  %pilha_ptr_var8 = load ptr, ptr %Loira, align 8
  %peeked_val9 = call i32 @pilha_peek(ptr %pilha_ptr_var8)
  %cmpeq10 = icmp eq i32 %peeked_val9, 3
  br i1 %cmpeq10, label %if_then11, label %if_merge12

if_then11:                                        ; preds = %if_merge
  %load_str13 = load ptr, ptr %Lembranca, align 8
  %str_substituida_ptr = call ptr @string_substituir(ptr %load_str13, ptr @alvo_str, ptr @subst_str)
  store ptr %str_substituida_ptr, ptr %Lembranca, align 8
  %tmpstr14 = load ptr, ptr %Lembranca, align 8
  %2 = call i32 (ptr, ...) @printf(ptr @fmt.2, ptr %tmpstr14)
  br label %if_merge12

if_merge12:                                       ; preds = %if_then11, %if_merge
  %pilha_ptr_var15 = load ptr, ptr %Loira, align 8
  %peeked_val16 = call i32 @pilha_peek(ptr %pilha_ptr_var15)
  %cmpeq17 = icmp eq i32 %peeked_val16, 1
  br i1 %cmpeq17, label %if_then18, label %if_merge19

if_then18:                                        ; preds = %if_merge12
  %load_str20 = load ptr, ptr %Lembranca, align 8
  %str_concatenada_ptr21 = call ptr @string_concatenar(ptr %load_str20, ptr @add_str.3)
  store ptr %str_concatenada_ptr21, ptr %Lembranca, align 8
  %tmpstr22 = load ptr, ptr %Lembranca, align 8
  %3 = call i32 (ptr, ...) @printf(ptr @fmt.4, ptr %tmpstr22)
  br label %if_merge19

if_merge19:                                       ; preds = %if_then18, %if_merge12
  %pilha_ptr_var23 = load ptr, ptr %Loira, align 8
  %peeked_val24 = call i32 @pilha_peek(ptr %pilha_ptr_var23)
  %cmpeq25 = icmp eq i32 %peeked_val24, 4
  br i1 %cmpeq25, label %if_then26, label %if_merge27

if_then26:                                        ; preds = %if_merge19
  %load_str28 = load ptr, ptr %Lembranca, align 8
  %str_substituida_ptr29 = call ptr @string_substituir(ptr %load_str28, ptr @alvo_str.5, ptr @subst_str.6)
  store ptr %str_substituida_ptr29, ptr %Lembranca, align 8
  %tmpstr30 = load ptr, ptr %Lembranca, align 8
  %4 = call i32 (ptr, ...) @printf(ptr @fmt.7, ptr %tmpstr30)
  br label %if_merge27

if_merge27:                                       ; preds = %if_then26, %if_merge19
  %pilha_ptr_var31 = load ptr, ptr %Loira, align 8
  %peeked_val32 = call i32 @pilha_peek(ptr %pilha_ptr_var31)
  %pilha_ptr_var33 = load ptr, ptr %Abismo, align 8
  %peeked_val34 = call i32 @pilha_peek(ptr %pilha_ptr_var33)
  %cmpgt = icmp sgt i32 %peeked_val32, %peeked_val34
  br i1 %cmpgt, label %if_then35, label %if_merge36

if_then35:                                        ; preds = %if_merge27
  store i1 false, ptr %"Esta chovendo4", align 1
  br label %if_merge36

if_merge36:                                       ; preds = %if_then35, %if_merge27
  br label %while_cond
=======
@prompt = private unnamed_addr constant [30 x i8] c"Digite o valor de Dia atual: \00", align 1
@fmt = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@prompt.1 = private unnamed_addr constant [30 x i8] c"Digite o valor de Mes atual: \00", align 1
@fmt.2 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg.3 = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@prompt.4 = private unnamed_addr constant [30 x i8] c"Digite o valor de Ano atual: \00", align 1
@fmt.5 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg.6 = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@prompt.7 = private unnamed_addr constant [43 x i8] c"Digite o valor de Dia do seu aniversario: \00", align 1
@fmt.8 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg.9 = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@prompt.10 = private unnamed_addr constant [43 x i8] c"Digite o valor de Mes do seu aniversario: \00", align 1
@fmt.11 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg.12 = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@prompt.13 = private unnamed_addr constant [40 x i8] c"Digite o valor de Ano que voce nasceu: \00", align 1
@fmt.14 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg.15 = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@fmt_str = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str = private unnamed_addr constant [11 x i8] c"caluladora\00", align 1

define i32 @main() {
entrada:
  %"Dia atual" = alloca ptr, align 8
  %nova_pilha_ptr = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr, i32 0)
  store ptr %nova_pilha_ptr, ptr %"Dia atual", align 8
  %"Mes atual" = alloca ptr, align 8
  %nova_pilha_ptr1 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr1, i32 0)
  store ptr %nova_pilha_ptr1, ptr %"Mes atual", align 8
  %"Ano atual" = alloca ptr, align 8
  %nova_pilha_ptr2 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr2, i32 0)
  store ptr %nova_pilha_ptr2, ptr %"Ano atual", align 8
  %"Dia do seu aniversario" = alloca ptr, align 8
  %nova_pilha_ptr3 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr3, i32 0)
  store ptr %nova_pilha_ptr3, ptr %"Dia do seu aniversario", align 8
  %"Mes do seu aniversario" = alloca ptr, align 8
  %nova_pilha_ptr4 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr4, i32 0)
  store ptr %nova_pilha_ptr4, ptr %"Mes do seu aniversario", align 8
  %"Ano que voce nasceu" = alloca ptr, align 8
  %nova_pilha_ptr5 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr5, i32 0)
  store ptr %nova_pilha_ptr5, ptr %"Ano que voce nasceu", align 8
  %caluladora = alloca ptr, align 8
  %nova_pilha_ptr6 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr6, i32 0)
  store ptr %nova_pilha_ptr6, ptr %caluladora, align 8
  %0 = call i32 (ptr, ...) @printf(ptr @prompt)
  %temp_scanf = alloca i32, align 4
  %res_scanf = call i32 (ptr, ...) @scanf(ptr @fmt, ptr %temp_scanf)
  %scanf_failed = icmp ne i32 %res_scanf, 1
  br i1 %scanf_failed, label %erro, label %ok

ok:                                               ; preds = %erro, %entrada
  %valor_lido = load i32, ptr %temp_scanf, align 4
  %pilha_ptr = load ptr, ptr %"Dia atual", align 8
  call void @pilha_set_topo(ptr %pilha_ptr, i32 %valor_lido)
  %1 = call i32 (ptr, ...) @printf(ptr @prompt.1)
  %temp_scanf7 = alloca i32, align 4
  %res_scanf8 = call i32 (ptr, ...) @scanf(ptr @fmt.2, ptr %temp_scanf7)
  %scanf_failed9 = icmp ne i32 %res_scanf8, 1
  br i1 %scanf_failed9, label %erro11, label %ok10

erro:                                             ; preds = %entrada
  %2 = call i32 (ptr, ...) @printf(ptr @errmsg)
  br label %ok

ok10:                                             ; preds = %erro11, %ok
  %valor_lido12 = load i32, ptr %temp_scanf7, align 4
  %pilha_ptr13 = load ptr, ptr %"Mes atual", align 8
  call void @pilha_set_topo(ptr %pilha_ptr13, i32 %valor_lido12)
  %3 = call i32 (ptr, ...) @printf(ptr @prompt.4)
  %temp_scanf14 = alloca i32, align 4
  %res_scanf15 = call i32 (ptr, ...) @scanf(ptr @fmt.5, ptr %temp_scanf14)
  %scanf_failed16 = icmp ne i32 %res_scanf15, 1
  br i1 %scanf_failed16, label %erro18, label %ok17

erro11:                                           ; preds = %ok
  %4 = call i32 (ptr, ...) @printf(ptr @errmsg.3)
  br label %ok10

ok17:                                             ; preds = %erro18, %ok10
  %valor_lido19 = load i32, ptr %temp_scanf14, align 4
  %pilha_ptr20 = load ptr, ptr %"Ano atual", align 8
  call void @pilha_set_topo(ptr %pilha_ptr20, i32 %valor_lido19)
  %5 = call i32 (ptr, ...) @printf(ptr @prompt.7)
  %temp_scanf21 = alloca i32, align 4
  %res_scanf22 = call i32 (ptr, ...) @scanf(ptr @fmt.8, ptr %temp_scanf21)
  %scanf_failed23 = icmp ne i32 %res_scanf22, 1
  br i1 %scanf_failed23, label %erro25, label %ok24

erro18:                                           ; preds = %ok10
  %6 = call i32 (ptr, ...) @printf(ptr @errmsg.6)
  br label %ok17

ok24:                                             ; preds = %erro25, %ok17
  %valor_lido26 = load i32, ptr %temp_scanf21, align 4
  %pilha_ptr27 = load ptr, ptr %"Dia do seu aniversario", align 8
  call void @pilha_set_topo(ptr %pilha_ptr27, i32 %valor_lido26)
  %7 = call i32 (ptr, ...) @printf(ptr @prompt.10)
  %temp_scanf28 = alloca i32, align 4
  %res_scanf29 = call i32 (ptr, ...) @scanf(ptr @fmt.11, ptr %temp_scanf28)
  %scanf_failed30 = icmp ne i32 %res_scanf29, 1
  br i1 %scanf_failed30, label %erro32, label %ok31

erro25:                                           ; preds = %ok17
  %8 = call i32 (ptr, ...) @printf(ptr @errmsg.9)
  br label %ok24

ok31:                                             ; preds = %erro32, %ok24
  %valor_lido33 = load i32, ptr %temp_scanf28, align 4
  %pilha_ptr34 = load ptr, ptr %"Mes do seu aniversario", align 8
  call void @pilha_set_topo(ptr %pilha_ptr34, i32 %valor_lido33)
  %9 = call i32 (ptr, ...) @printf(ptr @prompt.13)
  %temp_scanf35 = alloca i32, align 4
  %res_scanf36 = call i32 (ptr, ...) @scanf(ptr @fmt.14, ptr %temp_scanf35)
  %scanf_failed37 = icmp ne i32 %res_scanf36, 1
  br i1 %scanf_failed37, label %erro39, label %ok38

erro32:                                           ; preds = %ok24
  %10 = call i32 (ptr, ...) @printf(ptr @errmsg.12)
  br label %ok31

ok38:                                             ; preds = %erro39, %ok31
  %valor_lido40 = load i32, ptr %temp_scanf35, align 4
  %pilha_ptr41 = load ptr, ptr %"Ano que voce nasceu", align 8
  call void @pilha_set_topo(ptr %pilha_ptr41, i32 %valor_lido40)
  %pilha_ptr_var = load ptr, ptr %"Ano atual", align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr_var)
  %pilha_ptr_var42 = load ptr, ptr %"Ano que voce nasceu", align 8
  %peeked_val43 = call i32 @pilha_peek(ptr %pilha_ptr_var42)
  %subtmp = sub i32 %peeked_val, %peeked_val43
  %pilha_ptr44 = load ptr, ptr %caluladora, align 8
  call void @pilha_set_topo(ptr %pilha_ptr44, i32 %subtmp)
  %pilha_ptr_var45 = load ptr, ptr %"Mes atual", align 8
  %peeked_val46 = call i32 @pilha_peek(ptr %pilha_ptr_var45)
  %pilha_ptr_var47 = load ptr, ptr %"Mes do seu aniversario", align 8
  %peeked_val48 = call i32 @pilha_peek(ptr %pilha_ptr_var47)
  %cmple = icmp sle i32 %peeked_val46, %peeked_val48
  br i1 %cmple, label %if_then, label %if_merge

erro39:                                           ; preds = %ok31
  %11 = call i32 (ptr, ...) @printf(ptr @errmsg.15)
  br label %ok38

if_then:                                          ; preds = %ok38
  %pilha_ptr_var49 = load ptr, ptr %"Dia atual", align 8
  %peeked_val50 = call i32 @pilha_peek(ptr %pilha_ptr_var49)
  %pilha_ptr_var51 = load ptr, ptr %"Dia do seu aniversario", align 8
  %peeked_val52 = call i32 @pilha_peek(ptr %pilha_ptr_var51)
  %cmplt = icmp slt i32 %peeked_val50, %peeked_val52
  br i1 %cmplt, label %if_then53, label %if_merge54

if_merge:                                         ; preds = %if_merge54, %ok38
  %pilha_ptr57 = load ptr, ptr %caluladora, align 8
  %peeked_val58 = call i32 @pilha_peek(ptr %pilha_ptr57)
  %12 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val58)
  ret i32 0

if_then53:                                        ; preds = %if_then
  %pilha_ptr55 = load ptr, ptr %caluladora, align 8
  %peeked_val56 = call i32 @pilha_peek(ptr %pilha_ptr55)
  %tmp_sum = add i32 %peeked_val56, -1
  call void @pilha_set_topo(ptr %pilha_ptr55, i32 %tmp_sum)
  br label %if_merge54

if_merge54:                                       ; preds = %if_then53, %if_then
  br label %if_merge
>>>>>>> main
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare ptr @string_criar(ptr)

declare void @pilha_set_topo(ptr, i32)

declare i32 @printf(ptr, ...)

declare i32 @pilha_peek(ptr)
<<<<<<< HEAD

declare ptr @string_concatenar(ptr, ptr)

declare ptr @string_substituir(ptr, ptr, ptr)
=======
>>>>>>> main
