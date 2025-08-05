; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

<<<<<<< HEAD
@prompt = private unnamed_addr constant [33 x i8] c"Digite o valor de Numero primo: \00", align 1
=======
@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@prompt = private unnamed_addr constant [32 x i8] c"Digite o valor de Jose Dirceu: \00", align 1
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
@fmt = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@prompt.1 = private unnamed_addr constant [32 x i8] c"Digite o valor de Jose Dirceu: \00", align 1
@fmt.2 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg.3 = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@fmt_str = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
<<<<<<< HEAD
@var_name_str = private unnamed_addr constant [10 x i8] c"Resultado\00", align 1
@fmt_str.1 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.2 = private unnamed_addr constant [10 x i8] c"Resultado\00", align 1
@fmt_str.3 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.4 = private unnamed_addr constant [10 x i8] c"Resultado\00", align 1
@fmt_str.5 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.6 = private unnamed_addr constant [10 x i8] c"Resultado\00", align 1

define i32 @main() {
entrada:
  %"Numero primo" = alloca ptr, align 8
  %nova_pilha_ptr = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr, i32 0)
  store ptr %nova_pilha_ptr, ptr %"Numero primo", align 8
  %Resultado = alloca ptr, align 8
  %nova_pilha_ptr1 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr1, i32 0)
  store ptr %nova_pilha_ptr1, ptr %Resultado, align 8
  %programa = alloca ptr, align 8
  %nova_pilha_ptr2 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr2, i32 0)
  store ptr %nova_pilha_ptr2, ptr %programa, align 8
  %"Jose Dirceu" = alloca ptr, align 8
  %nova_pilha_ptr3 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr3, i32 0)
  store ptr %nova_pilha_ptr3, ptr %"Jose Dirceu", align 8
  %"Maria Roberta" = alloca ptr, align 8
  %nova_pilha_ptr4 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr4, i32 0)
  store ptr %nova_pilha_ptr4, ptr %"Maria Roberta", align 8
=======
@var_name_str = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca ptr, align 8
  %nova_pilha_ptr = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr, i32 0)
  store ptr %nova_pilha_ptr, ptr %"Jose Dirceu", align 8
  %Mariazinha = alloca ptr, align 8
  %nova_pilha_ptr1 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr1, i32 0)
  store ptr %nova_pilha_ptr1, ptr %Mariazinha, align 8
  %"o mundo dos n meros" = alloca ptr, align 8
  store ptr @empty_str, ptr %"o mundo dos n meros", align 8
  store ptr @strtmp, ptr %"o mundo dos n meros", align 8
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
  %0 = call i32 (ptr, ...) @printf(ptr @prompt)
  %temp_scanf = alloca i32, align 4
  %res_scanf = call i32 (ptr, ...) @scanf(ptr @fmt, ptr %temp_scanf)
  %scanf_failed = icmp ne i32 %res_scanf, 1
  br i1 %scanf_failed, label %erro, label %ok

ok:                                               ; preds = %erro, %entrada
  %valor_lido = load i32, ptr %temp_scanf, align 4
<<<<<<< HEAD
  %pilha_ptr = load ptr, ptr %"Numero primo", align 8
  call void @pilha_set_topo(ptr %pilha_ptr, i32 %valor_lido)
  %pilha_ptr_var = load ptr, ptr %"Numero primo", align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr_var)
  %cmple = icmp sle i32 %peeked_val, 1
  br i1 %cmple, label %if_then, label %if_merge
=======
  %pilha_ptr = load ptr, ptr %"Jose Dirceu", align 8
  call void @pilha_set_topo(ptr %pilha_ptr, i32 %valor_lido)
  br label %while_cond
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647

erro:                                             ; preds = %entrada
  %1 = call i32 (ptr, ...) @printf(ptr @errmsg)
  br label %ok

<<<<<<< HEAD
if_then:                                          ; preds = %ok
  %pilha_ptr5 = load ptr, ptr %Resultado, align 8
  %peeked_val6 = call i32 @pilha_peek(ptr %pilha_ptr5)
  %2 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val6)
  call void @exit(i32 0)
  unreachable

if_merge:                                         ; preds = %depois_exit, %ok
  %pilha_ptr_var7 = load ptr, ptr %"Numero primo", align 8
  %peeked_val8 = call i32 @pilha_peek(ptr %pilha_ptr_var7)
  %cmpeq = icmp eq i32 %peeked_val8, 2
  br i1 %cmpeq, label %if_then9, label %if_merge10

depois_exit:                                      ; No predecessors!
  br label %if_merge

if_then9:                                         ; preds = %if_merge
  %pilha_ptr11 = load ptr, ptr %Resultado, align 8
  %peeked_val12 = call i32 @pilha_peek(ptr %pilha_ptr11)
  %tmp_sum = add i32 %peeked_val12, 1
  call void @pilha_set_topo(ptr %pilha_ptr11, i32 %tmp_sum)
  %pilha_ptr13 = load ptr, ptr %Resultado, align 8
  %peeked_val14 = call i32 @pilha_peek(ptr %pilha_ptr13)
  %3 = call i32 (ptr, ...) @printf(ptr @fmt_str.1, ptr @var_name_str.2, i32 %peeked_val14)
  call void @exit(i32 0)
  unreachable

if_merge10:                                       ; preds = %depois_exit15, %if_merge
  %pilha_ptr16 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val17 = call i32 @pilha_peek(ptr %pilha_ptr16)
  %tmp_sum18 = add i32 %peeked_val17, 2
  call void @pilha_set_topo(ptr %pilha_ptr16, i32 %tmp_sum18)
  %pilha_ptr19 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val20 = call i32 @pilha_peek(ptr %pilha_ptr19)
  %tmp_sum21 = add i32 %peeked_val20, 2
  call void @pilha_set_topo(ptr %pilha_ptr19, i32 %tmp_sum21)
  br label %while_cond
=======
while_cond:                                       ; preds = %ok6, %ok
  %pilha_ptr_var = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr_var)
  %cmpgt = icmp sgt i32 %peeked_val, 0
  br i1 %cmpgt, label %while_body, label %while_merge

while_body:                                       ; preds = %while_cond
  %pilha_ptr2 = load ptr, ptr %"Jose Dirceu", align 8
  call void @pilha_push(ptr %pilha_ptr2, i32 0)
  %2 = call i32 (ptr, ...) @printf(ptr @prompt.1)
  %temp_scanf3 = alloca i32, align 4
  %res_scanf4 = call i32 (ptr, ...) @scanf(ptr @fmt.2, ptr %temp_scanf3)
  %scanf_failed5 = icmp ne i32 %res_scanf4, 1
  br i1 %scanf_failed5, label %erro7, label %ok6
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647

depois_exit15:                                    ; No predecessors!
  br label %if_merge10

while_cond:                                       ; preds = %while_merge30, %if_merge10
  %pilha_ptr_var22 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val23 = call i32 @pilha_peek(ptr %pilha_ptr_var22)
  %pilha_ptr_var24 = load ptr, ptr %"Numero primo", align 8
  %peeked_val25 = call i32 @pilha_peek(ptr %pilha_ptr_var24)
  %divtmp = sdiv i32 %peeked_val25, 2
  %cmple26 = icmp sle i32 %peeked_val23, %divtmp
  br i1 %cmple26, label %while_body, label %while_merge

while_body:                                       ; preds = %while_cond
  %pilha_ptr27 = load ptr, ptr %"Maria Roberta", align 8
  call void @pilha_push(ptr %pilha_ptr27, i32 0)
  br label %while_cond28

while_merge:                                      ; preds = %while_cond
<<<<<<< HEAD
  %pilha_ptr55 = load ptr, ptr %Resultado, align 8
  %peeked_val56 = call i32 @pilha_peek(ptr %pilha_ptr55)
  %tmp_sum57 = add i32 %peeked_val56, 1
  call void @pilha_set_topo(ptr %pilha_ptr55, i32 %tmp_sum57)
  %pilha_ptr58 = load ptr, ptr %Resultado, align 8
  %peeked_val59 = call i32 @pilha_peek(ptr %pilha_ptr58)
  %4 = call i32 (ptr, ...) @printf(ptr @fmt_str.5, ptr @var_name_str.6, i32 %peeked_val59)
  ret i32 0

while_cond28:                                     ; preds = %if_merge45, %while_body
  %pilha_ptr_var31 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val32 = call i32 @pilha_peek(ptr %pilha_ptr_var31)
  %pilha_ptr_var33 = load ptr, ptr %"Numero primo", align 8
  %peeked_val34 = call i32 @pilha_peek(ptr %pilha_ptr_var33)
  %divtmp35 = sdiv i32 %peeked_val34, 2
  %cmple36 = icmp sle i32 %peeked_val32, %divtmp35
  br i1 %cmple36, label %while_body29, label %while_merge30

while_body29:                                     ; preds = %while_cond28
  %pilha_ptr_var37 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val38 = call i32 @pilha_peek(ptr %pilha_ptr_var37)
  %pilha_ptr_var39 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val40 = call i32 @pilha_peek(ptr %pilha_ptr_var39)
  %multmp = mul i32 %peeked_val38, %peeked_val40
  %pilha_ptr_var41 = load ptr, ptr %"Numero primo", align 8
  %peeked_val42 = call i32 @pilha_peek(ptr %pilha_ptr_var41)
  %cmpeq43 = icmp eq i32 %multmp, %peeked_val42
  br i1 %cmpeq43, label %if_then44, label %if_merge45

while_merge30:                                    ; preds = %while_cond28
  %pilha_ptr52 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val53 = call i32 @pilha_peek(ptr %pilha_ptr52)
  %tmp_sum54 = add i32 %peeked_val53, 1
  call void @pilha_set_topo(ptr %pilha_ptr52, i32 %tmp_sum54)
  br label %while_cond

if_then44:                                        ; preds = %while_body29
  %pilha_ptr46 = load ptr, ptr %Resultado, align 8
  %peeked_val47 = call i32 @pilha_peek(ptr %pilha_ptr46)
  %5 = call i32 (ptr, ...) @printf(ptr @fmt_str.3, ptr @var_name_str.4, i32 %peeked_val47)
  call void @exit(i32 0)
  unreachable

if_merge45:                                       ; preds = %depois_exit48, %while_body29
  %pilha_ptr49 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val50 = call i32 @pilha_peek(ptr %pilha_ptr49)
  %tmp_sum51 = add i32 %peeked_val50, 1
  call void @pilha_set_topo(ptr %pilha_ptr49, i32 %tmp_sum51)
  br label %while_cond28

depois_exit48:                                    ; No predecessors!
  br label %if_merge45
=======
  %pilha_ptr10 = load ptr, ptr %"Jose Dirceu", align 8
  %popped_val = call i32 @pilha_pop(ptr %pilha_ptr10)
  br label %while_cond11

ok6:                                              ; preds = %erro7, %while_body
  %valor_lido8 = load i32, ptr %temp_scanf3, align 4
  %pilha_ptr9 = load ptr, ptr %"Jose Dirceu", align 8
  call void @pilha_set_topo(ptr %pilha_ptr9, i32 %valor_lido8)
  br label %while_cond

erro7:                                            ; preds = %while_body
  %3 = call i32 (ptr, ...) @printf(ptr @errmsg.3)
  br label %ok6

while_cond11:                                     ; preds = %while_body12, %while_merge
  %pilha_ptr_size = load ptr, ptr %"Jose Dirceu", align 8
  %tamanho_pilha = call i32 @pilha_obter_tamanho(ptr %pilha_ptr_size)
  %cmpgt14 = icmp sgt i32 %tamanho_pilha, 0
  br i1 %cmpgt14, label %while_body12, label %while_merge13

while_body12:                                     ; preds = %while_cond11
  %pilha_ptr15 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val16 = call i32 @pilha_peek(ptr %pilha_ptr15)
  %4 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val16)
  %pilha_ptr17 = load ptr, ptr %"Jose Dirceu", align 8
  %popped_val18 = call i32 @pilha_pop(ptr %pilha_ptr17)
  br label %while_cond11

while_merge13:                                    ; preds = %while_cond11
  ret i32 0
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @printf(ptr, ...)

declare i32 @scanf(ptr, ...)

declare void @pilha_set_topo(ptr, i32)

declare i32 @pilha_peek(ptr)

<<<<<<< HEAD
declare void @exit(i32)
=======
declare i32 @pilha_pop(ptr)

declare i32 @pilha_obter_tamanho(ptr)
>>>>>>> 503dd52e4826217b5941649294e273ef8ccfc647
