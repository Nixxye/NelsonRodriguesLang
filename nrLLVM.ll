; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

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
  %"Jose Dirceu" = alloca ptr, align 8
  %nova_pilha_ptr = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr, i32 0)
  store ptr %nova_pilha_ptr, ptr %"Jose Dirceu", align 8
  %"Maria Roberta" = alloca ptr, align 8
  %nova_pilha_ptr1 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr1, i32 0)
  store ptr %nova_pilha_ptr1, ptr %"Maria Roberta", align 8
  %"Dia atual" = alloca ptr, align 8
  %nova_pilha_ptr2 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr2, i32 0)
  store ptr %nova_pilha_ptr2, ptr %"Dia atual", align 8
  %"Mes atual" = alloca ptr, align 8
  %nova_pilha_ptr3 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr3, i32 0)
  store ptr %nova_pilha_ptr3, ptr %"Mes atual", align 8
  %"Ano atual" = alloca ptr, align 8
  %nova_pilha_ptr4 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr4, i32 0)
  store ptr %nova_pilha_ptr4, ptr %"Ano atual", align 8
  %"Dia do seu aniversario" = alloca ptr, align 8
  %nova_pilha_ptr5 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr5, i32 0)
  store ptr %nova_pilha_ptr5, ptr %"Dia do seu aniversario", align 8
  %"Mes do seu aniversario" = alloca ptr, align 8
  %nova_pilha_ptr6 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr6, i32 0)
  store ptr %nova_pilha_ptr6, ptr %"Mes do seu aniversario", align 8
  %"Ano que voce nasceu" = alloca ptr, align 8
  %nova_pilha_ptr7 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr7, i32 0)
  store ptr %nova_pilha_ptr7, ptr %"Ano que voce nasceu", align 8
  %caluladora = alloca ptr, align 8
  %nova_pilha_ptr8 = call ptr @criar_pilha(i32 8)
  call void @pilha_push(ptr %nova_pilha_ptr8, i32 0)
  store ptr %nova_pilha_ptr8, ptr %caluladora, align 8
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
  %temp_scanf9 = alloca i32, align 4
  %res_scanf10 = call i32 (ptr, ...) @scanf(ptr @fmt.2, ptr %temp_scanf9)
  %scanf_failed11 = icmp ne i32 %res_scanf10, 1
  br i1 %scanf_failed11, label %erro13, label %ok12

erro:                                             ; preds = %entrada
  %2 = call i32 (ptr, ...) @printf(ptr @errmsg)
  br label %ok

ok12:                                             ; preds = %erro13, %ok
  %valor_lido14 = load i32, ptr %temp_scanf9, align 4
  %pilha_ptr15 = load ptr, ptr %"Mes atual", align 8
  call void @pilha_set_topo(ptr %pilha_ptr15, i32 %valor_lido14)
  %3 = call i32 (ptr, ...) @printf(ptr @prompt.4)
  %temp_scanf16 = alloca i32, align 4
  %res_scanf17 = call i32 (ptr, ...) @scanf(ptr @fmt.5, ptr %temp_scanf16)
  %scanf_failed18 = icmp ne i32 %res_scanf17, 1
  br i1 %scanf_failed18, label %erro20, label %ok19

erro13:                                           ; preds = %ok
  %4 = call i32 (ptr, ...) @printf(ptr @errmsg.3)
  br label %ok12

ok19:                                             ; preds = %erro20, %ok12
  %valor_lido21 = load i32, ptr %temp_scanf16, align 4
  %pilha_ptr22 = load ptr, ptr %"Ano atual", align 8
  call void @pilha_set_topo(ptr %pilha_ptr22, i32 %valor_lido21)
  %5 = call i32 (ptr, ...) @printf(ptr @prompt.7)
  %temp_scanf23 = alloca i32, align 4
  %res_scanf24 = call i32 (ptr, ...) @scanf(ptr @fmt.8, ptr %temp_scanf23)
  %scanf_failed25 = icmp ne i32 %res_scanf24, 1
  br i1 %scanf_failed25, label %erro27, label %ok26

erro20:                                           ; preds = %ok12
  %6 = call i32 (ptr, ...) @printf(ptr @errmsg.6)
  br label %ok19

ok26:                                             ; preds = %erro27, %ok19
  %valor_lido28 = load i32, ptr %temp_scanf23, align 4
  %pilha_ptr29 = load ptr, ptr %"Dia do seu aniversario", align 8
  call void @pilha_set_topo(ptr %pilha_ptr29, i32 %valor_lido28)
  %7 = call i32 (ptr, ...) @printf(ptr @prompt.10)
  %temp_scanf30 = alloca i32, align 4
  %res_scanf31 = call i32 (ptr, ...) @scanf(ptr @fmt.11, ptr %temp_scanf30)
  %scanf_failed32 = icmp ne i32 %res_scanf31, 1
  br i1 %scanf_failed32, label %erro34, label %ok33

erro27:                                           ; preds = %ok19
  %8 = call i32 (ptr, ...) @printf(ptr @errmsg.9)
  br label %ok26

ok33:                                             ; preds = %erro34, %ok26
  %valor_lido35 = load i32, ptr %temp_scanf30, align 4
  %pilha_ptr36 = load ptr, ptr %"Mes do seu aniversario", align 8
  call void @pilha_set_topo(ptr %pilha_ptr36, i32 %valor_lido35)
  %9 = call i32 (ptr, ...) @printf(ptr @prompt.13)
  %temp_scanf37 = alloca i32, align 4
  %res_scanf38 = call i32 (ptr, ...) @scanf(ptr @fmt.14, ptr %temp_scanf37)
  %scanf_failed39 = icmp ne i32 %res_scanf38, 1
  br i1 %scanf_failed39, label %erro41, label %ok40

erro34:                                           ; preds = %ok26
  %10 = call i32 (ptr, ...) @printf(ptr @errmsg.12)
  br label %ok33

ok40:                                             ; preds = %erro41, %ok33
  %valor_lido42 = load i32, ptr %temp_scanf37, align 4
  %pilha_ptr43 = load ptr, ptr %"Ano que voce nasceu", align 8
  call void @pilha_set_topo(ptr %pilha_ptr43, i32 %valor_lido42)
  %pilha_ptr_var = load ptr, ptr %"Ano atual", align 8
  %peeked_val = call i32 @pilha_peek(ptr %pilha_ptr_var)
  %pilha_ptr_var44 = load ptr, ptr %"Ano que voce nasceu", align 8
  %peeked_val45 = call i32 @pilha_peek(ptr %pilha_ptr_var44)
  %subtmp = sub i32 %peeked_val, %peeked_val45
  %pilha_ptr46 = load ptr, ptr %caluladora, align 8
  call void @pilha_set_topo(ptr %pilha_ptr46, i32 %subtmp)
  %pilha_ptr_var47 = load ptr, ptr %"Mes atual", align 8
  %peeked_val48 = call i32 @pilha_peek(ptr %pilha_ptr_var47)
  %pilha_ptr_var49 = load ptr, ptr %"Mes do seu aniversario", align 8
  %peeked_val50 = call i32 @pilha_peek(ptr %pilha_ptr_var49)
  %cmple = icmp sle i32 %peeked_val48, %peeked_val50
  br i1 %cmple, label %if_then, label %if_merge

erro41:                                           ; preds = %ok33
  %11 = call i32 (ptr, ...) @printf(ptr @errmsg.15)
  br label %ok40

if_then:                                          ; preds = %ok40
  %pilha_ptr_var51 = load ptr, ptr %"Dia atual", align 8
  %peeked_val52 = call i32 @pilha_peek(ptr %pilha_ptr_var51)
  %pilha_ptr_var53 = load ptr, ptr %"Dia do seu aniversario", align 8
  %peeked_val54 = call i32 @pilha_peek(ptr %pilha_ptr_var53)
  %cmplt = icmp slt i32 %peeked_val52, %peeked_val54
  br i1 %cmplt, label %if_then55, label %if_merge56

if_merge:                                         ; preds = %if_merge56, %ok40
  %pilha_ptr59 = load ptr, ptr %caluladora, align 8
  %peeked_val60 = call i32 @pilha_peek(ptr %pilha_ptr59)
  %12 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %peeked_val60)
  ret i32 0

if_then55:                                        ; preds = %if_then
  %pilha_ptr57 = load ptr, ptr %caluladora, align 8
  %peeked_val58 = call i32 @pilha_peek(ptr %pilha_ptr57)
  %tmp_sum = add i32 %peeked_val58, -1
  call void @pilha_set_topo(ptr %pilha_ptr57, i32 %tmp_sum)
  br label %if_merge56

if_merge56:                                       ; preds = %if_then55, %if_then
  br label %if_merge
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @printf(ptr, ...)

declare i32 @scanf(ptr, ...)

declare void @pilha_set_topo(ptr, i32)

declare i32 @pilha_peek(ptr)
