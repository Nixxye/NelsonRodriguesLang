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
}

declare ptr @criar_pilha(i32)

declare void @pilha_push(ptr, i32)

declare i32 @printf(ptr, ...)

declare i32 @scanf(ptr, ...)

declare void @pilha_set_topo(ptr, i32)

declare i32 @pilha_peek(ptr)
