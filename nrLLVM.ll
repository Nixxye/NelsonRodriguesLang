; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@fmt_str = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@prompt = private unnamed_addr constant [30 x i8] c"Digite o valor de Joaozinho: \00", align 1
@fmt = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@fmt_str.1 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.2 = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@fmt_str.3 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.4 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1
@fmt_str.5 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.6 = private unnamed_addr constant [11 x i8] c"Robertinha\00", align 1
@fmt_str.7 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.8 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1
@fmt_str.9 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.10 = private unnamed_addr constant [10 x i8] c"Joaozinho\00", align 1
@fmt_str.11 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.12 = private unnamed_addr constant [10 x i8] c"Joaozinho\00", align 1
@fmt_str.13 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.14 = private unnamed_addr constant [10 x i8] c"Joaozinho\00", align 1

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
  %Joaozinho = alloca ptr, align 8
  %nova_pilha_ptr2 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr2, i32 0)
  store ptr %nova_pilha_ptr2, ptr %Joaozinho, align 8
  %Robertinha = alloca ptr, align 8
  %nova_pilha_ptr3 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr3, i32 0)
  store ptr %nova_pilha_ptr3, ptr %Robertinha, align 8
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @empty_str, ptr %"Avenida Copacabana", align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
  %"Esta chovendo" = alloca i1, align 1
  store i1 false, ptr %"Esta chovendo", align 1
  store i1 true, ptr %"Esta chovendo", align 1
  %pilha_ptr = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr)
  %0 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val)
  %pilha_ptr4 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val5 = call i32 @pilha_peek(ptr %pilha_ptr4)
  %tmp_sum = add i32 %peeked_val5, 1
  call void @pilha_set_topo(ptr %pilha_ptr4, i32 %tmp_sum)
  %pilha_ptr6 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val7 = call i32 @pilha_peek(ptr %pilha_ptr6)
  %tmp_sum8 = add i32 %peeked_val7, 1
  call void @pilha_set_topo(ptr %pilha_ptr6, i32 %tmp_sum8)
  %1 = call i32 (ptr, ...) @printf(ptr @prompt)
  %temp_scanf = alloca i32, align 4
  %res_scanf = call i32 (ptr, ...) @scanf(ptr @fmt, ptr %temp_scanf)
  %scanf_failed = icmp ne i32 %res_scanf, 1
  br i1 %scanf_failed, label %erro, label %ok

ok:                                               ; preds = %erro, %entrada
  %valor_lido = load i32, ptr %temp_scanf, align 4
  %pilha_ptr9 = load ptr, ptr %Joaozinho, align 8
  call void @pilha_set_topo(ptr %pilha_ptr9, i32 %valor_lido)
  %pilha_ptr10 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val11 = call i32 @pilha_peek(ptr %pilha_ptr10)
  %2 = call i32 (ptr, ...) @printf(ptr @fmt_str.1, ptr @var_name_str.2, i32 %peeked_val11)
  %pilha_ptr12 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val13 = call i32 @pilha_peek(ptr %pilha_ptr12)
  %3 = call i32 (ptr, ...) @printf(ptr @fmt_str.3, ptr @var_name_str.4, i32 %peeked_val13)
  %pilha_ptr_var = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val14 = call i32 @pilha_peek(ptr %pilha_ptr_var)
  %addtmp = add i32 %peeked_val14, 0
  %pilha_ptr15 = load ptr, ptr %Robertinha, align 8
  call void @pilha_set_topo(ptr %pilha_ptr15, i32 %addtmp)
  br label %while_cond

erro:                                             ; preds = %entrada
  %4 = call i32 (ptr, ...) @printf(ptr @errmsg)
  br label %ok

while_cond:                                       ; preds = %while_body, %ok
  %pilha_ptr_var16 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val17 = call i32 @pilha_peek(ptr %pilha_ptr_var16)
  %pilha_ptr_var18 = load ptr, ptr %Joaozinho, align 8
  %peeked_val19 = call i32 @pilha_peek(ptr %pilha_ptr_var18)
  %cmplt = icmp slt i32 %peeked_val17, %peeked_val19
  br i1 %cmplt, label %while_body, label %while_merge

while_body:                                       ; preds = %while_cond
  %pilha_ptr_var20 = load ptr, ptr %Robertinha, align 8
  %peeked_val21 = call i32 @pilha_peek(ptr %pilha_ptr_var20)
  %addtmp22 = add i32 0, %peeked_val21
  %pilha_ptr23 = load ptr, ptr %"Jose Dirceu", align 8
  call void @pilha_set_topo(ptr %pilha_ptr23, i32 %addtmp22)
  %pilha_ptr_var24 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val25 = call i32 @pilha_peek(ptr %pilha_ptr_var24)
  %addtmp26 = add i32 %peeked_val25, 1
  %pilha_ptr27 = load ptr, ptr %Robertinha, align 8
  call void @pilha_set_topo(ptr %pilha_ptr27, i32 %addtmp26)
  %pilha_ptr28 = load ptr, ptr %Robertinha, align 8
  %peeked_val29 = call i32 @pilha_peek(ptr %pilha_ptr28)
  %5 = call i32 (ptr, ...) @printf(ptr @fmt_str.5, ptr @var_name_str.6, i32 %peeked_val29)
  %pilha_ptr30 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val31 = call i32 @pilha_peek(ptr %pilha_ptr30)
  %6 = call i32 (ptr, ...) @printf(ptr @fmt_str.7, ptr @var_name_str.8, i32 %peeked_val31)
  %pilha_ptr32 = load ptr, ptr %Joaozinho, align 8
  %peeked_val33 = call i32 @pilha_peek(ptr %pilha_ptr32)
  %7 = call i32 (ptr, ...) @printf(ptr @fmt_str.9, ptr @var_name_str.10, i32 %peeked_val33)
  br label %while_cond

while_merge:                                      ; preds = %while_cond
  %pilha_ptr_var34 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val35 = call i32 @pilha_peek(ptr %pilha_ptr_var34)
  %addtmp36 = add i32 %peeked_val35, 3
  %pilha_ptr37 = load ptr, ptr %Joaozinho, align 8
  call void @pilha_set_topo(ptr %pilha_ptr37, i32 %addtmp36)
  br label %do_body

do_body:                                          ; preds = %do_cond, %while_merge
  %pilha_ptr38 = load ptr, ptr %Joaozinho, align 8
  %peeked_val39 = call i32 @pilha_peek(ptr %pilha_ptr38)
  %tmp_sum40 = add i32 %peeked_val39, -1
  call void @pilha_set_topo(ptr %pilha_ptr38, i32 %tmp_sum40)
  %pilha_ptr41 = load ptr, ptr %Joaozinho, align 8
  %peeked_val42 = call i32 @pilha_peek(ptr %pilha_ptr41)
  %8 = call i32 (ptr, ...) @printf(ptr @fmt_str.11, ptr @var_name_str.12, i32 %peeked_val42)
  %pilha_ptr_var43 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val44 = call i32 @pilha_peek(ptr %pilha_ptr_var43)
  %pilha_ptr_var45 = load ptr, ptr %Joaozinho, align 8
  %peeked_val46 = call i32 @pilha_peek(ptr %pilha_ptr_var45)
  %cmplt47 = icmp slt i32 %peeked_val44, %peeked_val46
  br label %do_cond

do_cond:                                          ; preds = %do_body
  br i1 %cmplt47, label %do_body, label %do_merge

do_merge:                                         ; preds = %do_cond
  %pilha_ptr48 = load ptr, ptr %Joaozinho, align 8
  %peeked_val49 = call i32 @pilha_peek(ptr %pilha_ptr48)
  %9 = call i32 (ptr, ...) @printf(ptr @fmt_str.13, ptr @var_name_str.14, i32 %peeked_val49)
  ret i32 0
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @printf(ptr, ...)

declare i32 @pilha_peek(ptr)

declare void @pilha_set_topo(ptr, i32)

declare i32 @scanf(ptr, ...)
