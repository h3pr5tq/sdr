function [ S_est ] = MF(R)
% R - матрица со статистиками;
%   каждый столбец соответствует одному отдельному SEFDM-символу
% 
	S_est = slicing(R);

end

