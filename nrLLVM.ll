; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@fmt = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@fmt.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@fmt.2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca i32, align 4
  store i32 0, ptr %"Jose Dirceu", align 4
  %"Maria Roberta" = alloca i32, align 4
  store i32 0, ptr %"Maria Roberta", align 4
  %Joaozinho = alloca i32, align 4
  store i32 0, ptr %Joaozinho, align 4
  %Robertinha = alloca i32, align 4
  store i32 0, ptr %Robertinha, align 4
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
  %"Esta chovendo" = alloca i1, align 1
  store i1 false, ptr %"Esta chovendo", align 1
  store i1 true, ptr %"Esta chovendo", align 1
  %tmpint = load i32, ptr %"Maria Roberta", align 4
  %0 = call i32 (ptr, ...) @printf(ptr @fmt, i32 %tmpint)
  %tmp_load = load i32, ptr %"Maria Roberta", align 4
  %tmp_sum = add i32 %tmp_load, 1
  store i32 %tmp_sum, ptr %"Maria Roberta", align 4
  %tmp_load1 = load i32, ptr %"Jose Dirceu", align 4
  %tmp_sum2 = add i32 %tmp_load1, 1
  store i32 %tmp_sum2, ptr %"Jose Dirceu", align 4
  %tmpint3 = load i32, ptr %"Maria Roberta", align 4
  %1 = call i32 (ptr, ...) @printf(ptr @fmt.1, i32 %tmpint3)
  %tmpint4 = load i32, ptr %"Jose Dirceu", align 4
  %2 = call i32 (ptr, ...) @printf(ptr @fmt.2, i32 %tmpint4)
  %load_var = load i32, ptr %"Jose Dirceu", align 4
  %addtmp = add i32 %load_var, 0
  %tmp_load5 = load i32, ptr %Robertinha, align 4
  %tmp_sum6 = add i32 %tmp_load5, %addtmp
  store i32 %tmp_sum6, ptr %Robertinha, align 4
  ret i32 0
}

declare i32 @printf(ptr, ...)
