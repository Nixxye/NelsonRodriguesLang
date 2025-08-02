; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@empty_str = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@empty_str.1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@strtmp.2 = private unnamed_addr constant [31 x i8] c"nao sei o que nao sei o que la\00", align 1
@fmt_str = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@prompt = private unnamed_addr constant [30 x i8] c"Digite o valor de Joaozinho: \00", align 1
@fmt = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@fmt_str.3 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.4 = private unnamed_addr constant [10 x i8] c"Joaozinho\00", align 1
@fmt_str.5 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.6 = private unnamed_addr constant [10 x i8] c"Joaozinho\00", align 1
@prompt.7 = private unnamed_addr constant [30 x i8] c"Digite o valor de Joaozinho: \00", align 1
@fmt.8 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg.9 = private unnamed_addr constant [43 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\\n\00", align 1
@fmt_str.10 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.11 = private unnamed_addr constant [10 x i8] c"Joaozinho\00", align 1
@fmt_str.12 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.13 = private unnamed_addr constant [10 x i8] c"Joaozinho\00", align 1

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
  %"Cenario 2" = alloca ptr, align 8
  store ptr @empty_str.1, ptr %"Cenario 2", align 8
  store ptr @strtmp.2, ptr %"Cenario 2", align 8
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
  %pilha_ptr10 = load ptr, ptr %Joaozinho, align 8
  %peeked_val11 = call i32 @pilha_peek(ptr %pilha_ptr10)
  %2 = call i32 (ptr, ...) @printf(ptr @fmt_str.3, ptr @var_name_str.4, i32 %peeked_val11)
  %pilha_ptr12 = load ptr, ptr %Joaozinho, align 8
  call void @pilha_push(ptr %pilha_ptr12, i32 0)
  %pilha_ptr13 = load ptr, ptr %Joaozinho, align 8
  %peeked_val14 = call i32 @pilha_peek(ptr %pilha_ptr13)
  %3 = call i32 (ptr, ...) @printf(ptr @fmt_str.5, ptr @var_name_str.6, i32 %peeked_val14)
  %4 = call i32 (ptr, ...) @printf(ptr @prompt.7)
  %temp_scanf15 = alloca i32, align 4
  %res_scanf16 = call i32 (ptr, ...) @scanf(ptr @fmt.8, ptr %temp_scanf15)
  %scanf_failed17 = icmp ne i32 %res_scanf16, 1
  br i1 %scanf_failed17, label %erro19, label %ok18

erro:                                             ; preds = %entrada
  %5 = call i32 (ptr, ...) @printf(ptr @errmsg)
  br label %ok

ok18:                                             ; preds = %erro19, %ok
  %valor_lido20 = load i32, ptr %temp_scanf15, align 4
  %pilha_ptr21 = load ptr, ptr %Joaozinho, align 8
  call void @pilha_set_topo(ptr %pilha_ptr21, i32 %valor_lido20)
  %pilha_ptr22 = load ptr, ptr %Joaozinho, align 8
  %peeked_val23 = call i32 @pilha_peek(ptr %pilha_ptr22)
  %6 = call i32 (ptr, ...) @printf(ptr @fmt_str.10, ptr @var_name_str.11, i32 %peeked_val23)
  %pilha_ptr24 = load ptr, ptr %Joaozinho, align 8
  %popped_val = call i32 @pilha_pop(ptr %pilha_ptr24)
  %pilha_ptr25 = load ptr, ptr %Joaozinho, align 8
  %peeked_val26 = call i32 @pilha_peek(ptr %pilha_ptr25)
  %7 = call i32 (ptr, ...) @printf(ptr @fmt_str.12, ptr @var_name_str.13, i32 %peeked_val26)
  %load_var = load i32, ptr %"Jose Dirceu", align 4
  %addtmp = add i32 %load_var, 0
  %pilha_ptr27 = load ptr, ptr %Robertinha, align 8
  %peeked_val28 = call i32 @pilha_peek(ptr %pilha_ptr27)
  %tmp_sum29 = add i32 %peeked_val28, %addtmp
  call void @pilha_set_topo(ptr %pilha_ptr27, i32 %tmp_sum29)
  ret i32 0

erro19:                                           ; preds = %ok
  %8 = call i32 (ptr, ...) @printf(ptr @errmsg.9)
  br label %ok18
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @printf(ptr, ...)

declare i32 @pilha_peek(ptr)

declare void @pilha_set_topo(ptr, i32)

declare i32 @scanf(ptr, ...)

declare i32 @pilha_pop(ptr)
