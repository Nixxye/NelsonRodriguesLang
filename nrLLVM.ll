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
@errmsg = private unnamed_addr constant [42 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\0A\00", align 1
@fmt_str.3 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.4 = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@fmt_str.5 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.6 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1

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
  %tmp_load = load i32, ptr %"Maria Roberta", align 4
  %tmp_sum = add i32 %tmp_load, 1
  store i32 %tmp_sum, ptr %"Maria Roberta", align 4
  %tmp_load4 = load i32, ptr %"Jose Dirceu", align 4
  %tmp_sum5 = add i32 %tmp_load4, 1
  store i32 %tmp_sum5, ptr %"Jose Dirceu", align 4
  %1 = call i32 (ptr, ...) @printf(ptr @prompt)
  %res_scanf = call i32 (ptr, ...) @scanf(ptr @fmt, ptr %Joaozinho)
  %scanf_failed = icmp ne i32 %res_scanf, 1
  br i1 %scanf_failed, label %erro, label %ok

ok:                                               ; preds = %erro, %entrada
  %pilha_ptr6 = load ptr, ptr %"Maria Roberta", align 8
  %peeked_val7 = call i32 @pilha_peek(ptr %pilha_ptr6)
  %2 = call i32 (ptr, ...) @printf(ptr @fmt_str.3, ptr @var_name_str.4, i32 %peeked_val7)
  %pilha_ptr8 = load ptr, ptr %"Jose Dirceu", align 8
  %peeked_val9 = call i32 @pilha_peek(ptr %pilha_ptr8)
  %3 = call i32 (ptr, ...) @printf(ptr @fmt_str.5, ptr @var_name_str.6, i32 %peeked_val9)
  %load_var = load i32, ptr %"Jose Dirceu", align 4
  %addtmp = add i32 %load_var, 0
  %tmp_load10 = load i32, ptr %Robertinha, align 4
  %tmp_sum11 = add i32 %tmp_load10, %addtmp
  store i32 %tmp_sum11, ptr %Robertinha, align 4
  ret i32 0

erro:                                             ; preds = %entrada
  %4 = call i32 (ptr, ...) @printf(ptr @errmsg)
  br label %ok
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @printf(ptr, ...)

declare i32 @pilha_peek(ptr)

declare i32 @scanf(ptr, ...)
