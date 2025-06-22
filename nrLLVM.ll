; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

<<<<<<< HEAD
@strtmp = private unnamed_addr constant [19 x i8] c"luxuria e confusao\00", align 1
@strtmp.1 = private unnamed_addr constant [36 x i8] c"luxuria e confusao pica de cachorro\00", align 1
@fmt = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@strtmp.2 = private unnamed_addr constant [36 x i8] c"luxuria e confusao pila de cachorro\00", align 1
@fmt.3 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@prompt = private unnamed_addr constant [32 x i8] c"Digite valor de Maria Roberta: \00", align 1
@fmt.4 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@errmsg = private unnamed_addr constant [42 x i8] c"Erro: valor inv\C3\A1lido (esperado inteiro)\0A\00", align 1
@fmt.5 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
=======
@strtmp = private unnamed_addr constant [20 x i8] c"luxuria  e confusao\00", align 1
>>>>>>> origin/Main_while

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca i32, align 4
  store i32 0, ptr %"Jose Dirceu", align 4
  %"Maria Roberta" = alloca i32, align 4
  store i32 0, ptr %"Maria Roberta", align 4
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
<<<<<<< HEAD
  %"Esta chovendo" = alloca i1, align 1
  store i1 false, ptr %"Esta chovendo", align 1
  store i1 true, ptr %"Esta chovendo", align 1
  store ptr @strtmp.1, ptr %"Avenida Copacabana", align 8
  %tmpstr = load ptr, ptr %"Avenida Copacabana", align 8
  %0 = call i32 (ptr, ...) @printf(ptr @fmt, ptr %tmpstr)
  store ptr @strtmp.2, ptr %"Avenida Copacabana", align 8
  store i1 false, ptr %"Esta chovendo", align 1
  %tmpstr1 = load ptr, ptr %"Avenida Copacabana", align 8
  %1 = call i32 (ptr, ...) @printf(ptr @fmt.3, ptr %tmpstr1)
  store i32 2, ptr %"Maria Roberta", align 4
  %2 = call i32 (ptr, ...) @printf(ptr @prompt)
  %res_scanf = call i32 (ptr, ...) @scanf(ptr @fmt.4, ptr %"Maria Roberta")
  %scanf_failed = icmp ne i32 %res_scanf, 1
  br i1 %scanf_failed, label %erro, label %ok

ok:                                               ; preds = %erro, %entrada
  %tmpint = load i32, ptr %"Maria Roberta", align 4
  %3 = call i32 (ptr, ...) @printf(ptr @fmt.5, i32 %tmpint)
  store i32 -2, ptr %"Jose Dirceu", align 4
  store i32 0, ptr %"Maria Roberta", align 4
  ret i32 0

erro:                                             ; preds = %entrada
  %4 = call i32 (ptr, ...) @printf(ptr @errmsg)
  br label %ok
}

declare i32 @printf(ptr, ...)

declare i32 @scanf(ptr, ...)
=======
  store i32 2, ptr %"Maria Roberta", align 4
  store i32 -2, ptr %"Jose Dirceu", align 4
  store i32 1, ptr %"Maria Roberta", align 4
  store i32 0, ptr %"Maria Roberta", align 4
  store i32 -1, ptr %"Maria Roberta", align 4
  ret i32 0
}
>>>>>>> origin/Main_while
