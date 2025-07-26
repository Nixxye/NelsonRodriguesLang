; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@strtmp.1 = private unnamed_addr constant [31 x i8] c"nao sei o que nao sei o que la\00", align 1
@fmt_str = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@stack_name_arg = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@stack_name_arg.2 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1
@prompt = private unnamed_addr constant [30 x i8] c"Digite o valor de Joaozinho: \00", align 1
@fmt = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg = private unnamed_addr constant [42 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\0A\00", align 1
@fmt_str.3 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.4 = private unnamed_addr constant [14 x i8] c"Maria Roberta\00", align 1
@fmt_str.5 = private unnamed_addr constant [13 x i8] c"%s: Sou %d!\0A\00", align 1
@var_name_str.6 = private unnamed_addr constant [12 x i8] c"Jose Dirceu\00", align 1

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca i32, align 4
  %"Maria Roberta" = alloca i32, align 4
  %Joaozinho = alloca i32, align 4
  %Robertinha = alloca i32, align 4
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
  %"Cenario 2" = alloca ptr, align 8
  store ptr @strtmp.1, ptr %"Cenario 2", align 8
  %"Esta chovendo" = alloca i1, align 1
  store i1 false, ptr %"Esta chovendo", align 1
  store i1 true, ptr %"Esta chovendo", align 1
  %tmpint = load i32, ptr %"Maria Roberta", align 4
  %0 = call i32 (ptr, ...) @printf(ptr @fmt_str, ptr @var_name_str, i32 %tmpint)
  call void @set_int_value(ptr @stack_name_arg, i32 1)
  call void @set_int_value(ptr @stack_name_arg.2, i32 1)
  %1 = call i32 (ptr, ...) @printf(ptr @prompt)
  %res_scanf = call i32 (ptr, ...) @scanf(ptr @fmt, ptr %Joaozinho)
  %scanf_failed = icmp ne i32 %res_scanf, 1
  br i1 %scanf_failed, label %erro, label %ok

ok:                                               ; preds = %erro, %entrada
  %tmpint1 = load i32, ptr %"Maria Roberta", align 4
  %2 = call i32 (ptr, ...) @printf(ptr @fmt_str.3, ptr @var_name_str.4, i32 %tmpint1)
  %tmpint2 = load i32, ptr %"Jose Dirceu", align 4
  %3 = call i32 (ptr, ...) @printf(ptr @fmt_str.5, ptr @var_name_str.6, i32 %tmpint2)
  %load_var = load i32, ptr %"Jose Dirceu", align 4
  %addtmp = add i32 %load_var, 0
  %tmp_load = load i32, ptr %Robertinha, align 4
  %tmp_sum = add i32 %tmp_load, %addtmp
  store i32 %tmp_sum, ptr %Robertinha, align 4
  ret i32 0

erro:                                             ; preds = %entrada
  %4 = call i32 (ptr, ...) @printf(ptr @errmsg)
  br label %ok
}

declare i32 @printf(ptr, ...)

declare void @set_int_value(ptr, i32)

declare i32 @scanf(ptr, ...)
