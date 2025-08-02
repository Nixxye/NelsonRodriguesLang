; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@empty_str.1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@strtmp.2 = private unnamed_addr constant [31 x i8] c"nao sei o que nao sei o que la\00", align 1
@fmt_str = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@fmt_str.3 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.4 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1
@fmt_str.5 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
<<<<<<< HEAD
@var_name_str.6 = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
=======
@var_name_str.6 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1
@prompt = private unnamed_addr constant [32 x i8] c"Digite o valor de Jose Dirceu: \00", align 1
@fmt = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
>>>>>>> db9b9798927a93bd1676703678280ef1b802f3a7
@fmt_str.7 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.8 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca ptr, align 8
  %nova_pilha_ptr = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr, i32 0)
  store ptr %nova_pilha_ptr, ptr %"Jose Dirceu", align 8
  %"Maria Roberta" = alloca ptr, align 8
  %nova_pilha_ptr1 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr1, i32 0)
  store ptr %nova_pilha_ptr1, ptr %"Maria Roberta", align 8
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @empty_str, ptr %"Avenida Copacabana", align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
  %"Cenario 2" = alloca ptr, align 8
  store ptr @empty_str.1, ptr %"Cenario 2", align 8
  store ptr @strtmp.2, ptr %"Cenario 2", align 8
  %pilha_ptr = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr)
  %tmp_sum = add i32 %peeked_val, 1
  call void @pilha_set_topo(ptr %pilha_ptr, i32 %tmp_sum)
<<<<<<< HEAD
  %pilha_ptr2 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val3 = call i32 @pilha_peek(ptr %pilha_ptr2)
  %tmp_sum4 = add i32 %peeked_val3, -1
  call void @pilha_set_topo(ptr %pilha_ptr2, i32 %tmp_sum4)
  %pilha_ptr5 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val6 = call i32 @pilha_peek(ptr %pilha_ptr5)
  %0 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val6)
=======
  %pilha_ptr2 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val3 = call i32 @pilha_peek(ptr %pilha_ptr2)
  %0 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val3)
  %pilha_ptr4 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val5 = call i32 @pilha_peek(ptr %pilha_ptr4)
  %tmp_sum6 = add i32 %peeked_val5, -1
  call void @pilha_set_topo(ptr %pilha_ptr4, i32 %tmp_sum6)
>>>>>>> db9b9798927a93bd1676703678280ef1b802f3a7
  %pilha_ptr7 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val8 = call i32 @pilha_peek(ptr %pilha_ptr7)
  %1 = call i32 (ptr, ...) @printf(ptr @fmt_str.3, ptr @var_name_str.4, i32 %peeked_val8)
  %pilha_ptr_var = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val9 = call i32 @pilha_peek(ptr %pilha_ptr_var)
<<<<<<< HEAD
  %pilha_ptr_var10 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val11 = call i32 @pilha_peek(ptr %pilha_ptr_var10)
  %cmpgt = icmp sgt i32 %peeked_val9, %peeked_val11
  %pilha_ptr12 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val13 = call i32 @pilha_peek(ptr %pilha_ptr12)
  %tmp_sum14 = add i32 %peeked_val13, -1
  call void @pilha_set_topo(ptr %pilha_ptr12, i32 %tmp_sum14)
  %pilha_ptr15 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val16 = call i32 @pilha_peek(ptr %pilha_ptr15)
  %tmp_sum17 = add i32 %peeked_val16, 1
  call void @pilha_set_topo(ptr %pilha_ptr15, i32 %tmp_sum17)
  br i1 %cmpgt, label %if_then_bloco, label %if_merge_bloco

if_then_bloco:                                    ; preds = %entrada
  br label %if_merge_bloco

if_merge_bloco:                                   ; preds = %if_then_bloco, %entrada
  %pilha_ptr18 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val19 = call i32 @pilha_peek(ptr %pilha_ptr18)
  %2 = call i32 (ptr, ...) @printf(ptr @fmt_str.5, ptr @var_name_str.6, i32 %peeked_val19)
  %pilha_ptr20 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val21 = call i32 @pilha_peek(ptr %pilha_ptr20)
  %3 = call i32 (ptr, ...) @printf(ptr @fmt_str.7, ptr @var_name_str.8, i32 %peeked_val21)
=======
  %pilha_ptr_eu = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val10 = call i32 @pilha_peek(ptr %pilha_ptr_eu)
  %cmplt = icmp slt i32 %peeked_val9, %peeked_val10
  %pilha_ptr_eu11 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val12 = call i32 @pilha_peek(ptr %pilha_ptr_eu11)
  br i1 %cmplt, label %if_then, label %if_merge

if_then:                                          ; preds = %entrada
  %pilha_ptr13 = load ptr, ptr %"Jose Dirceu", align 8
  call void @pilha_set_topo(ptr %pilha_ptr13, i32 %peeked_val12)
  br label %if_merge

if_merge:                                         ; preds = %if_then, %entrada
  %pilha_ptr14 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val15 = call i32 @pilha_peek(ptr %pilha_ptr14)
  %2 = call i32 (ptr, ...) @printf(ptr @fmt_str.5, ptr @var_name_str.6, i32 %peeked_val15)
  %pilha_ptr_voce = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val16 = call i32 @pilha_peek(ptr %pilha_ptr_voce)
  %pilha_ptr_eu17 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val18 = call i32 @pilha_peek(ptr %pilha_ptr_eu17)
  %cmpngt = icmp sle i32 %peeked_val16, %peeked_val18
  br i1 %cmpngt, label %if_then19, label %if_merge20

if_then19:                                        ; preds = %if_merge
  %3 = call i32 (ptr, ...) @printf(ptr @prompt)
  %temp_scanf = alloca i32, align 4
  %res_scanf = call i32 (ptr, ...) @scanf(ptr @fmt, ptr %temp_scanf)
  %scanf_failed = icmp ne i32 %res_scanf, 1
  br i1 %scanf_failed, label %erro, label %ok

if_merge20:                                       ; preds = %ok, %if_merge
  %pilha_ptr_voce22 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val23 = call i32 @pilha_peek(ptr %pilha_ptr_voce22)
  %pilha_ptr_eu24 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val25 = call i32 @pilha_peek(ptr %pilha_ptr_eu24)
  %cmpngt26 = icmp sle i32 %peeked_val23, %peeked_val25
  br i1 %cmpngt26, label %if_then27, label %if_merge28

ok:                                               ; preds = %erro, %if_then19
  %valor_lido = load i32, ptr %temp_scanf, align 4
  %pilha_ptr21 = load ptr, ptr %"Jose Dirceu", align 8
  call void @pilha_set_topo(ptr %pilha_ptr21, i32 %valor_lido)
  br label %if_merge20

erro:                                             ; preds = %if_then19
  %4 = call i32 (ptr, ...) @printf(ptr @errmsg)
  br label %ok

if_then27:                                        ; preds = %if_merge20
  %pilha_ptr29 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val30 = call i32 @pilha_peek(ptr %pilha_ptr29)
  %5 = call i32 (ptr, ...) @printf(ptr @fmt_str.7, ptr @var_name_str.8, i32 %peeked_val30)
  br label %if_merge28

if_merge28:                                       ; preds = %if_then27, %if_merge20
>>>>>>> db9b9798927a93bd1676703678280ef1b802f3a7
  ret i32 0
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @pilha_peek(ptr)

declare void @pilha_set_topo(ptr, i32)

declare i32 @printf(ptr, ...)
<<<<<<< HEAD
=======

declare i32 @scanf(ptr, ...)
>>>>>>> db9b9798927a93bd1676703678280ef1b802f3a7
