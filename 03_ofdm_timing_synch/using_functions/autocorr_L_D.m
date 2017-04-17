function [ c, m ] = autocorr_L_D( r, L, D )
%
% Выполняет автокорреляцию входной последовательности @r
% со своей копией, сдвинутой на @D отсчётов;
% размер окна суммирования - @L
% Также выполняется нормировка
%
% Для чего?: детектирование начала пакета (ОБНАРУЖЕНИЕ сигнала)
%
% См., например,
% "OFDM Wireless LANs: A Theoretical and Practical Guide",
% Juha Heiskala, John Terry, стр. 58
%
% in:
%   @r - входной сигнал, массив-строка
%   @L - размер окна суммирования
%   @D - кол-во отсчётов на которое сдвигается копия входной
%     последовательности при автокорреляции
%
% out:
%   @c - модуль автокорреляции (вещественные числа),
%     массив-строка длина которого будет length(r)-L-D+1
%   @m - нормированные значения @c,
%     массив-строка длина которого будет length(r)-L-D+1
%

%
% Д О Б А В И Т Ь   О П Т И М И З А Ц И Ю   С
% П Р О М Е Ж У Т О Ч Н Ы М   Б У Ф Е Р О М !
% (buf = buf - first + last)
%

%
% C   О П Т И М И З А Ц И Е Й   П О Д   M A T L A B
%
        c = zeros(1, length(r) - L - D + 1);
        p = zeros(1, length(r) - L - D + 1);
        
        % По отсчётам входной последовательности
        for n = 1 : length(r) - L - D + 1
                
                c(n) = r(n + 0 : n + L - 1) * ...
                        r(n + D + 0 : n + D + L - 1)';
                
                p(n) = r(n + D + 0 : n + D + L - 1) * ...
                        r(n + D + 0 : n + D + L - 1)';
                
        end
        
        % Нормировка
        m = abs(c).^2 ./ p.^2;   
        c = abs(c);

%%
% Б Е З   О П Т И М И З А Ц И И   П О Д   M A T L A B
%
%         c = zeros(1, length(r) - L - D + 1);
%         p = zeros(1, length(r) - L - D + 1);
%         
%         % По отсчётам входной последовательности
%         for n = 1 : length(r) - L - D + 1
%                 
%                 % Окно суммирования
%                 for k = 0 : L - 1
%                         c(n) = c(n) + ...
%                                 r(n + k) * r(n + k + D)';
%                         
%                         p(n) = p(n) + ...
%                                 abs( r(n + k + D) ) ^ 2;
%                 end     
%                 
%         end
%         
%         % Нормировка
%         m = abs(c).^2 ./ p.^2;
%         c = abs(c);
        
end

