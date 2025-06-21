; ModuleID = 'NelsonRodriguesLang'
source_filename = "NelsonRodriguesLang"

@strtmp = private unnamed_addr constant [20 x i8] c"luxuria  e confusao\00", align 1
@strtmp.1 = private unnamed_addr constant [37 x i8] c"luxuria  e confusao pica de cachorro\00", align 1
@fmt = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@strtmp.2 = private unnamed_addr constant [37 x i8] c"luxuria  e confusao pila de cachorro\00", align 1
@fmt.3 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

define i32 @main() {
entrada:
  %"Jose Dirceu" = alloca i32, align 4
  store i32 0, ptr %"Jose Dirceu", align 4
  %"Maria Roberta" = alloca i32, align 4
  store i32 0, ptr %"Maria Roberta", align 4
  %"Avenida Copacabana" = alloca ptr, align 8
  store ptr @strtmp, ptr %"Avenida Copacabana", align 8
  store ptr @strtmp.1, ptr %"Avenida Copacabana", align 8
  %tmpstr = load ptr, ptr %"Avenida Copacabana", align 8
  %0 = call i32 (ptr, ...) @printf(ptr @fmt, ptr %tmpstr)
  store ptr @strtmp.2, ptr %"Avenida Copacabana", align 8
  %tmpstr1 = load ptr, ptr %"Avenida Copacabana", align 8
  %1 = call i32 (ptr, ...) @printf(ptr @fmt.3, ptr %tmpstr1)
  store i32 2, ptr %"Maria Roberta", align 4
  store i32 -2, ptr %"Jose Dirceu", align 4
  store i32 0, ptr %"Maria Roberta", align 4
  ret i32 0
}

declare i32 @printf(ptr, ...)
