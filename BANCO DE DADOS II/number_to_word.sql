SET GLOBAL log_bin_trust_function_creators = 1;

DELIMITER $$
CREATE FUNCTION `number_to_words`(n INT) RETURNS varchar(100)
BEGIN
    -- This function returns the string representation of a number.
    -- It's just an example... I'll restrict it to hundreds, but
    -- it can be extended easily.
    -- The idea is:
    --      For each digit you need a position,
    --      For each position, you assign a string
    declare ans varchar(100);
    declare dig1, dig2, dig3, dig4, dig5, dig6 int;

set ans = '';

set dig6 = CAST(RIGHT(CAST(floor(n / 100000) as CHAR(8)), 1) as SIGNED);
set dig5 = CAST(RIGHT(CAST(floor(n / 10000) as CHAR(8)), 1) as SIGNED);
set dig4 = CAST(RIGHT(CAST(floor(n / 1000) as CHAR(8)), 1) as SIGNED);
set dig3 = CAST(RIGHT(CAST(floor(n / 100) as CHAR(8)), 1) as SIGNED);
set dig2 = CAST(RIGHT(CAST(floor(n / 10) as CHAR(8)), 1) as SIGNED);
set dig1 = CAST(RIGHT(floor(n), 1) as SIGNED);

if dig6 > 0 then
    case
        when dig6=1 then set ans=concat(ans, 'cem');
        when dig6=2 then set ans=concat(ans, 'duzentos');
        when dig6=3 then set ans=concat(ans, 'trezentos');
        when dig6=4 then set ans=concat(ans, 'quatrocentos');
        when dig6=5 then set ans=concat(ans, 'quinhentos');
        when dig6=6 then set ans=concat(ans, 'seiscentos');
        when dig6=7 then set ans=concat(ans, 'setecentos');
        when dig6=8 then set ans=concat(ans, 'oitocentos');
        when dig6=9 then set ans=concat(ans, 'novecentos');
        else set ans = ans;
    end case;
end if;

if dig5 = 1 then
    case
        when (dig5*10 + dig4) = 10 then set ans=concat(ans, ' e dez mil ');
        when (dig5*10 + dig4) = 11 then set ans=concat(ans, ' e  onze mil ');
        when (dig5*10 + dig4) = 12 then set ans=concat(ans, ' e  doze mil ');
        when (dig5*10 + dig4) = 13 then set ans=concat(ans, ' e  Treze mil ');
        when (dig5*10 + dig4) = 14 then set ans=concat(ans, ' e  catorze mil ');
        when (dig5*10 + dig4) = 15 then set ans=concat(ans, ' e  quinze mil ');
        when (dig5*10 + dig4) = 16 then set ans=concat(ans, ' e  dezesseis mil ');
        when (dig5*10 + dig4) = 17 then set ans=concat(ans, ' e  dezessete mil ');
        when (dig5*10 + dig4) = 18 then set ans=concat(ans, ' e  dezoito mil ');
        when (dig5*10 + dig4) = 19 then set ans=concat(ans, ' e  dezenove mil ');
        else set ans=ans;
    end case;
else
    if dig5 > 0 then
        case
            when dig5=2 then set ans=concat(ans, ' e vinte');
            when dig5=3 then set ans=concat(ans, ' e trinta');
            when dig5=4 then set ans=concat(ans, ' e quarenta');
            when dig5=5 then set ans=concat(ans, ' e cinquenta');
            when dig5=6 then set ans=concat(ans, ' e sessenta');
            when dig5=7 then set ans=concat(ans, ' e setenta');
            when dig5=8 then set ans=concat(ans, ' e oitenta');
            when dig5=9 then set ans=concat(ans, ' e noventa');
            else set ans=ans;
        end case;
    end if;
    if dig4 > 0 then
        case
            when dig4=1 then set ans=concat(ans, ' mil ');
            when dig4=2 then set ans=concat(ans, ' dois mil ');
            when dig4=3 then set ans=concat(ans, ' três mil ');
            when dig4=4 then set ans=concat(ans, ' quatro mil ');
            when dig4=5 then set ans=concat(ans, ' cinco mil ');
            when dig4=6 then set ans=concat(ans, ' seis mil ');
            when dig4=7 then set ans=concat(ans, ' sete mil ');
            when dig4=8 then set ans=concat(ans, ' oito mil ');
            when dig4=9 then set ans=concat(ans, ' nove mil ');
            else set ans=ans;
        end case;
    end if;
    if dig4 = 0 AND (dig5 != 0 || dig6 != 0) then
        set ans=concat(ans, ' thousand ');
    end if;
end if;

if dig3 > 0 then
    case
        when dig3=1 then set ans=concat(ans, 'cem');
        when dig3=2 then set ans=concat(ans, 'duzentos');
        when dig3=3 then set ans=concat(ans, 'trezentos');
        when dig3=4 then set ans=concat(ans, 'quatrocentos');
        when dig3=5 then set ans=concat(ans, 'quinhentos');
        when dig3=6 then set ans=concat(ans, 'seiscentos');
        when dig3=7 then set ans=concat(ans, 'setecentos');
        when dig3=8 then set ans=concat(ans, 'oitocentos');
        when dig3=9 then set ans=concat(ans, 'novecentos');
        else set ans = ans;
    end case;
end if;

if dig2 = 1 then
    case
        when (dig2*10 + dig1) = 10 then set ans=concat(ans, ' e dez');
        when (dig2*10 + dig1) = 11 then set ans=concat(ans, ' e onze');
        when (dig2*10 + dig1) = 12 then set ans=concat(ans, ' e doze');
        when (dig2*10 + dig1) = 13 then set ans=concat(ans, ' e Treze');
        when (dig2*10 + dig1) = 14 then set ans=concat(ans, ' e quatorze');
        when (dig2*10 + dig1) = 15 then set ans=concat(ans, ' e quinze');
        when (dig2*10 + dig1) = 16 then set ans=concat(ans, ' e dezesseis');
        when (dig2*10 + dig1) = 17 then set ans=concat(ans, ' e dezessete');
        when (dig2*10 + dig1) = 18 then set ans=concat(ans, ' e dezoito');
        when (dig2*10 + dig1) = 19 then set ans=concat(ans, ' e dezenove');
        else set ans=ans;
    end case;
else
    if dig2 > 0 then
        case
            when dig2=2 then set ans=concat(ans, ' e vinte');
            when dig2=3 then set ans=concat(ans, ' e trinta');
            when dig2=4 then set ans=concat(ans, ' e quarenta');
            when dig2=5 then set ans=concat(ans, ' e cinquenta');
            when dig2=6 then set ans=concat(ans, ' e sessenta');
            when dig2=7 then set ans=concat(ans, ' e setenta');
            when dig2=8 then set ans=concat(ans, ' e oitenta');
            when dig2=9 then set ans=concat(ans, ' e noventa');
            else set ans=ans;
        end case;
    end if;
    if dig1 > 0 then
        case
            when dig1=1 then set ans=concat(ans, ' e um');
            when dig1=2 then set ans=concat(ans, ' e dois');
            when dig1=3 then set ans=concat(ans, ' e três');
            when dig1=4 then set ans=concat(ans, ' e quatro');
            when dig1=5 then set ans=concat(ans, ' e cinco');
            when dig1=6 then set ans=concat(ans, ' e seis');
            when dig1=7 then set ans=concat(ans, ' e Sete');
            when dig1=8 then set ans=concat(ans, ' e oito');
            when dig1=9 then set ans=concat(ans, ' e nove');
            else set ans=ans;
        end case;
    end if;
end if;

return trim(ans);
END
$$