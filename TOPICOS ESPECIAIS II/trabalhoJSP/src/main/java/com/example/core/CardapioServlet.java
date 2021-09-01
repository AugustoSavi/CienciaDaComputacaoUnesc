package com.example.core;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;

@WebServlet(name = "CardapioServlet", value = "/cardapio-servelet")
public class CardapioServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Collection<String> opcao= Arrays.asList(request.getParameterValues("opcao"));
        int sum = 0;
        for (String t : opcao) {
            int i = Integer.valueOf(t);
            sum += i;
        }
        System.out.println(sum);
        PrintWriter out = response.getWriter();
        out.println("soma:"+sum);

    }
}
