@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Hobby')
@section('page_description', 'Qui viene mostrato un solo hobby')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header">{{$hobby -> name}}</div>

                    <div class="card-body">
                        <p>{{$hobby -> description}}</p>
                    </div>
                </div>
                <div class="mt-3">
                    <a class="btn btn-link btn-sm" href="/hobby">
                        <i class="fas fa-arrow-circle-up"></i> Ritorna agli hobby
                    </a>
                </div>
            </div>
        </div>
@endsection
